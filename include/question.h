#ifndef QUESTION_H
#define QUESTION_H

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/object.h>
#include <ijengine/core/listener.h>
#include <ijengine/core/level.h>

#include <vector>

using std::vector;

class Question : public Level
{
public:
	Question(Object *parent, const string& title, const string& text,
        const vector<pair<string, string> >& buttons);

    typedef enum { YES, NO, UNKNOWN } Answer;

    Answer answer() const;
    bool waiting() const;
    bool on_message(Object *object, MessageID id, Parameters);
	ObjectID next();

private:
    bool m_waiting;
    Answer m_answer;
 	ObjectID id_button_click;
	void update_self(unsigned long elapsed);

    vector<string> split(const string& text) const;
};

#endif
