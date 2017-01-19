#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

#define MAX_SIZE 256
#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

const wchar_t *const DOWN = L"down";
const wchar_t *const UP = L"up";
const wchar_t *const LEFT = L"left";
const wchar_t *const RIGHT = L"right";

const wchar_t *const MOVE = L"move";
const wchar_t *const WALK = L"walk";

class AbstractNode
{
public:
     virtual wchar_t *Interpret() = 0;
};

class AndNode : public AbstractNode
{
public:
     AndNode(AbstractNode *left, AbstractNode *right) : m_pLeft(left), m_pRight(right){}

     wchar_t *Interpret()
     {
          wchar_t *pResult = new wchar_t[MAX_SIZE];
          memset(pResult, 0, MAX_SIZE * sizeof(wchar_t));

          wchar_t *pLeft = m_pLeft->Interpret();
          wchar_t *pRight = m_pRight->Interpret();
          wcscat_s(pResult, MAX_SIZE, pLeft);
          wcscat_s(pResult, MAX_SIZE, pRight);

          SAFE_DELETE(pLeft);
          SAFE_DELETE(m_pRight);

          return pResult;
     }

private:
     AbstractNode *m_pLeft;
     AbstractNode *m_pRight;
};

class SentenceNode : public AbstractNode
{
public:
     SentenceNode(AbstractNode *direction, AbstractNode *action, AbstractNode *distance) :
          m_pDirection(direction), m_pAction(action), m_pDistance(distance){}

     wchar_t *Interpret()
     {
          wchar_t *pResult = new wchar_t[MAX_SIZE];
          memset(pResult, 0, MAX_SIZE * sizeof(wchar_t));

          wchar_t *pDirection = m_pDirection->Interpret();
          wchar_t *pAction = m_pAction->Interpret();
          wchar_t *pDistance = m_pDistance->Interpret();
          wcscat_s(pResult, MAX_SIZE, pDirection);
          wcscat_s(pResult, MAX_SIZE, pAction);
          wcscat_s(pResult, MAX_SIZE, pDistance);

          SAFE_DELETE(pDirection);
          SAFE_DELETE(pAction);
          SAFE_DELETE(pDistance);

          return pResult;
     }

private:
     AbstractNode *m_pDirection;
     AbstractNode *m_pAction;
     AbstractNode *m_pDistance;
};

class DirectionNode : public AbstractNode
{
public:
     DirectionNode(wchar_t *direction) : m_pDirection(direction){}

     wchar_t *Interpret()
     {
          wchar_t *pResult = new wchar_t[MAX_SIZE];
          memset(pResult, 0, MAX_SIZE * sizeof(wchar_t));

          if (!_wcsicmp(m_pDirection, DOWN))
          {
               wcscat_s(pResult, MAX_SIZE, L"向下");
          }
          else if (!_wcsicmp(m_pDirection, UP))
          {
               wcscat_s(pResult, MAX_SIZE, L"向上");
          }
          else if (!_wcsicmp(m_pDirection, LEFT))
          {
               wcscat_s(pResult, MAX_SIZE, L"向左");
          }
          else if (!_wcsicmp(m_pDirection, RIGHT))
          {
               wcscat_s(pResult, MAX_SIZE, L"向右");
          }
          else
          {
               wcscat_s(pResult, MAX_SIZE, L"无效指令");
          }

          SAFE_DELETE(m_pDirection);
          return pResult;
     }

private:
     wchar_t *m_pDirection;
};

class ActionNode : public AbstractNode
{
public:
     ActionNode(wchar_t *action) : m_pAction(action){}

     wchar_t *Interpret()
     {
          wchar_t *pResult = new wchar_t[MAX_SIZE];
          memset(pResult, 0, MAX_SIZE * sizeof(wchar_t));

          if (!_wcsicmp(m_pAction, MOVE))
          {
               wcscat_s(pResult, MAX_SIZE, L"移动");
          }
          else if (!_wcsicmp(m_pAction, WALK))
          {
               wcscat_s(pResult, MAX_SIZE, L"走动");
          }
          else
          {
               wcscat_s(pResult, MAX_SIZE, L"无效指令");
          }

          SAFE_DELETE(m_pAction);
          return pResult;
     }

private:
     wchar_t *m_pAction;
};

class DistanceNode : public AbstractNode
{
public:
     DistanceNode(wchar_t *distance) : m_pDistance(distance){}

     wchar_t *Interpret()
     {
          wchar_t *pResult = new wchar_t[MAX_SIZE];
          memset(pResult, 0, MAX_SIZE * sizeof(wchar_t));

          wcscat_s(pResult, MAX_SIZE, m_pDistance);

          SAFE_DELETE(m_pDistance);
          return pResult;
     }

private:
     wchar_t *m_pDistance;
};

class InstructionHandler
{
public:
     InstructionHandler(wchar_t *instruction) : m_pInstruction(instruction), m_pTree(NULL){}

     void Handle();
     void Output();

private:
     void SplitInstruction(wchar_t **&instruction, int &size);

     wchar_t *m_pInstruction;
     AbstractNode *m_pTree;
};

void InstructionHandler::Handle()
{
     AbstractNode *pLeft = NULL;
     AbstractNode *pRight = NULL;
     AbstractNode *pDirection = NULL;
     AbstractNode *pAction = NULL;
     AbstractNode *pDistance = NULL;

     vector<AbstractNode *> node; // Store the instruction expression

     // Split the instruction by " "
     wchar_t **InstructionArray = NULL;
     int size;
     SplitInstruction(InstructionArray, size);
     for (int i = 0; i < size; ++i)
     {
          if (!_wcsicmp(InstructionArray[i], L"and")) // The instruction is composited by two expressions
          {
               wchar_t *pDirectionStr = InstructionArray[++i];
               pDirection = new DirectionNode(pDirectionStr);

               wchar_t *pActionStr = InstructionArray[++i];
               pAction = new ActionNode(pActionStr);

               wchar_t *pDistanceStr = InstructionArray[++i];
               pDistance = new DistanceNode(pDistanceStr);

               pRight = new SentenceNode(pDirection, pAction, pDistance);
               node.push_back(new AndNode(pLeft, pRight));
          }
          else
          {
               wchar_t *pDirectionStr = InstructionArray[i];
               pDirection = new DirectionNode(pDirectionStr);

               wchar_t *pActionStr = InstructionArray[++i];
               pAction = new ActionNode(pActionStr);

               wchar_t *pDistanceStr = InstructionArray[++i];
               pDistance = new DistanceNode(pDistanceStr);

               pLeft = new SentenceNode(pDirection, pAction, pDistance);
               node.push_back(pLeft);
          }
     }

     m_pTree = node[node.size() - 1];
}

void InstructionHandler::Output()
{
     wchar_t *pResult = m_pTree->Interpret();

     setlocale(LC_ALL,"");
     wprintf_s(L"%s\n", pResult);

     SAFE_DELETE(pResult);
}

void InstructionHandler::SplitInstruction(wchar_t **&instruction, int &size)
{
     instruction = new wchar_t*[10];
     memset(instruction, 0, 10 * sizeof( wchar_t*));

     for (int i = 0; i < 10; ++i)
     {
          instruction[i] = new wchar_t[10];
          memset(instruction[i], 0, 10 * sizeof(wchar_t));
     }

     size = 0;
     int n = 0;
     while (*m_pInstruction != L'\0')
     {
          if (*m_pInstruction == L' ')
          {
               size++;
               m_pInstruction++;
               n = 0;
               continue;
          }

          instruction[size][n++] = *m_pInstruction++;
     }
     size++;
}

int main()
{
     wchar_t *pInstructionStr = L"up move 5 and down walk 10";

     InstructionHandler *pInstructionHandler = new InstructionHandler(pInstructionStr);
     pInstructionHandler->Handle();
     pInstructionHandler->Output();

     SAFE_DELETE(pInstructionHandler);
}
