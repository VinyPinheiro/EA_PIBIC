#ifndef QUESTION_H
#define QUESTION_H

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/object.h>

class Question : public Object
{

public:
	Question(const string text, int posy,int size, Object *parent = nullptr, double x = 0, double y = 0);
	~Question();
    void start();
    bool stopped() const;
	void setY(int y);

private:
	void update_self(unsigned long elapsed);
    Text *question;
	bool m_working;
};

#endif
