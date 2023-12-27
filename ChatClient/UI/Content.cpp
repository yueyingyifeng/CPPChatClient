#include "Content.h"

int Content::max_width = 80;

deque<string> Content::getContent() const
{
    return content;
}

Content::Content()
{
    content = deque<string>();
}
