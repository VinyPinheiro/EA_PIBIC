#ifndef QUESTION_H
#define QUESTION_H

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/object.h>

#include <vector>

using std::vector;

class Question : public Object
{
public:
	Question(Object *parent, const string& title, const string& text,
        const string& okButton = "Sim", const string& cancelButton = "Não");

    typedef enum { YES, NO, UNKNOWN } Answer;

    Answer answer() const;
    bool waiting() const;

private:
    bool m_waiting;
    Answer m_answer;
 
	void update_self(unsigned long elapsed);

    vector<string> split(const string& text) const;
};

#endif
