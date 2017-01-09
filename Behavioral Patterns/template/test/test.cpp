class FileOperation
{
public:
     bool DownloadFile(wchar_t *pSrc, wchar_t *pDest)
     {
          if (!pSrc || !pDest) return false;
          if (!DoBeginDownloadFile(pSrc, pDest)) return false;
          if (!DoDownloadFile(pSrc, pDest)) return false;
          if (!DoEndDownloadFile(pSrc, pDest)) return false;
     }

protected:
     virtual bool DoBeginDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoEndDownloadFile(wchar_t *pSrc, wchar_t *pDest);
};

class HttpFileOperation : public FileOperation
{
protected:
     virtual bool DoBeginDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoEndDownloadFile(wchar_t *pSrc, wchar_t *pDest);
};

class SOAPFileOperation : public FileOperation
{
protected:
     virtual bool DoBeginDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoDownloadFile(wchar_t *pSrc, wchar_t *pDest);
     virtual bool DoEndDownloadFile(wchar_t *pSrc, wchar_t *pDest);
};
