#ifndef H_binaryExpressionTree
#define H_binaryExpressionTree

#include "binaryTree.h" // Assuming binaryTree.h defines binaryTreeType
#include <string>
#include <stack>

class binaryExpressionTree : public binaryTreeType<std::string> {
public:
    // Function to build an expression tree from a postfix expression
    void buildExpressionTree(const std::string& expression);

    // Function to evaluate the expression tree and return the result
    double evaluateExpressionTree();

    // Placeholder functions (stubs) for insert, deleteNode, and search
    bool search(const std::string& item) { return false; } // Stub function, not used in this project
    void insert(const std::string& item) {}                 // Stub function, not used in this project
    void deleteNode(const std::string& item) {}             // Stub function, not used in this project

private:
    // Helper function to evaluate the expression tree recursively
    double evaluateExpressionTree(nodeType<std::string>* node);
};

#endif