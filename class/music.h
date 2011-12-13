#ifndef MUSIC_H
#define MUSIC_H
#include<cstring>
#include"docs.h"
#include"multimedia.h"

class Music : public Multimedia
{
private:
    std::string _band;
public:

    //CONSTRUCT
    Music();
    Music(const std::string &band ,const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    virtual ~Music();

    //ACCESS
    virtual std::string getType();
    void setBand(const std::string&);
    std::string getBand() const;

    //OPERATOR
    virtual Music& operator=(const Music&);
    virtual bool operator==(const Music&) const;
};

#endif // MUSIC_H
