
class repository
{
private:
    nodetree* root;

public:
    repository()
    {
        root = NULL;
    }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int height(nodetree* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    nodetree* rightRotate(nodetree* y)
    {
        nodetree* x = y->leftroot;
        nodetree* T2 = x->rightroot;

        x->rightroot = y;
        y->leftroot = T2;

        y->height = max(height(y->leftroot), height(y->rightroot)) + 1;
        x->height = max(height(x->leftroot), height(x->rightroot)) + 1;

        return x;
    }
    nodetree* leftRotate(nodetree* x)
    {
        nodetree* y = x->rightroot;
        nodetree* T2 = y->leftroot;

        y->leftroot = x;
        x->rightroot = T2;

        x->height = max(height(x->leftroot), height(x->rightroot)) + 1;
        y->height = max(height(y->leftroot), height(y->rightroot)) + 1;

        return y;
    }
    int get_balance(nodetree* node)
    {
        if (node == NULL)
            return 0;
        return height(node->leftroot) - height(node->rightroot);
    }