#include <fstream>
class Log {
public:
    Log(){
        m_Out.open("./log.txt", std::ios::app); 
        m_Out<<std::unitbuf;
    }
    ~Log() {
        m_Out.flush();
        m_Out.close();
    }
    template <class T>
    Log& operator<<(const T& thing) { m_Out << thing; return *this; }
private:
    std::ofstream m_Out;
    //static LogFilter...
};
