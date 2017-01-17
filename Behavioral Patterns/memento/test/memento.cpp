#include <iostream>
#include <cstring> 
using namespace std;

struct State
{
     wchar_t wcsState[260];
};

class Memento
{
public:
     Memento(State *pState) : m_pState(pState){}

     State *GetState() { return m_pState; }

private:
     friend class Originator;

     State *m_pState;
};

class Originator
{
public:
     Originator() : m_pState(NULL) {}
     ~Originator()
     {
          // Delete the storage of the state
          if (m_pState)
          {
               delete m_pState;
               m_pState = NULL;
          }
     }

     void SetMemento(Memento *pMemento);
     Memento *CreateMemento();

     void SetValue(wchar_t *value)
     {
          memset(wcsValue, 0, 260 * sizeof(wchar_t));
          wcscpy_s(wcsValue, 260, value);
     }

     void PrintState() { wcout<<wcsValue<<endl; }

private:
     State *m_pState; // To store the object's state

     wchar_t wcsValue[260]; // This is the object's real data
};

Memento *Originator::CreateMemento()
{
     m_pState = new State;
     if (m_pState == NULL)
     {
          return NULL;
     }

     Memento *pMemento = new Memento(m_pState);

     wcscpy_s(m_pState->wcsState, 260, wcsValue); // Backup the value
     return pMemento;
}

void Originator::SetMemento(Memento *pMemento)
{
     m_pState = pMemento->GetState();

     // Recovery the data
     memset(wcsValue, 0, 260 * sizeof(wchar_t));
     wcscpy_s(wcsValue, 260, m_pState->wcsState);
}

// Manager the Memento
class Caretaker
{
public:
     Memento *GetMemento() { return m_pMemento; }
     void SetMemnto(Memento *pMemento)
     {
          // Free the previous Memento
          if (m_pMemento)
          {
               delete m_pMemento;
               m_pMemento = NULL;
          }

          // Set the new Memento
          m_pMemento = pMemento;
     }

private:
     Memento *m_pMemento;
};

int main()
{
     Originator *pOriginator = new Originator();
     pOriginator->SetValue(L"On");
     pOriginator->PrintState();

     // Now I backup the state
     Caretaker *pCaretaker = new Caretaker();
     pCaretaker->SetMemnto(pOriginator->CreateMemento());

     // Set the new state
     pOriginator->SetValue(L"Off");
     pOriginator->PrintState();

     // Recovery to the old state
     pOriginator->SetMemento(pCaretaker->GetMemento());
     pOriginator->PrintState();

     if (pCaretaker)
     {
          delete pCaretaker;
     }

     if (pOriginator)
     {
          delete pOriginator;
     }

     return 0;
}
