#include <iostream>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

class HolidayRequest
{
public:
     HolidayRequest(int hour) : m_iHour(hour){}
     int GetHour() { return m_iHour; }
private:
     int m_iHour;
};

// The holiday request handler interface
class Manager
{
public:
     virtual bool HandleRequest(HolidayRequest *pRequest) = 0;
};

// Project manager
class PM : public Manager
{
public:
     PM(Manager *handler) : m_pHandler(handler){}
     bool HandleRequest(HolidayRequest *pRequest)
     {
          if (pRequest->GetHour() <= 2 || m_pHandler == NULL)
          {
               cout<<"PM said:OK."<<endl;
               return true;
          }
          return m_pHandler->HandleRequest(pRequest);
     }
private:
     Manager *m_pHandler;
};

// Department manager
class DM : public Manager
{
public:
     DM(Manager *handler) : m_pHandler(handler){}
     bool HandleRequest(HolidayRequest *pRequest)
     {
          cout<<"DM said:OK."<<endl;
          return true;
     }

     // The department manager is in?
     bool IsIn()
     {
          return true;
     }
private:
     Manager *m_pHandler;
};

// Project supervisor
class PS : public Manager
{
public:
     PS(Manager *handler) : m_pHandler(handler){}
     bool HandleRequest(HolidayRequest *pRequest)
     {
          DM *pDM = dynamic_cast<DM *>(m_pHandler);
          if (pDM != NULL)
          {
               if (pDM->IsIn())
               {
                    return pDM->HandleRequest(pRequest);
               }
          }
          cout<<"PS said:OK."<<endl;
          return true;
     }
private:
     Manager *m_pHandler;
};
int main()
{
     DM *pDM = new DM(NULL);
     PS *pPS = new PS(pDM);
     PM *pPM = new PM(pPS);
     HolidayRequest *pHolidayRequest = new HolidayRequest(10);
     pPM->HandleRequest(pHolidayRequest);
     SAFE_DELETE(pHolidayRequest);

     pHolidayRequest = new HolidayRequest(2);
     pPM->HandleRequest(pHolidayRequest);

     SAFE_DELETE(pDM);
     SAFE_DELETE(pPS);
     SAFE_DELETE(pPM);
     SAFE_DELETE(pHolidayRequest);
}
