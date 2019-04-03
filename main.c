#include "ui.h"

int main(void)
{
    ProductRepo *repo = createRepo();
    Controller *ctrl  = createController(repo);

    startUI(ctrl);
    destroyController(ctrl);

    return 0;
}