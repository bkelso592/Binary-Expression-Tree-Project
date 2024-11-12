#include "binaryExpressionTree.h"
#include <sstream>
#include <stdexcept>

void binaryExpressionTree::buildExpressionTree(const std::string& expression) {
    std::stack<nodeType<std::string>*> nodeStack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        nodeType<std::string>* newNode = new nodeType<std::string>();
        newNode->info = token;
        newNode->lLink = newNode->rLink = nullptr;

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            newNode->rLink = nodeStack.top(); nodeStack.pop();
            newNode->lLink = nodeStack.top(); nodeStack.pop();
        }

        nodeStack.push(newNode);
    }

    root = nodeStack.top();
}

double binaryExpressionTree::evaluateExpressionTree() {
    return evaluateExpressionTree(root);
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* node) {
    if (node == nullptr) return 0;
    if (!node->lLink && !node->rLink) return std::stod(node->info);

    double left = evaluateExpressionTree(node->lLink);
    double right = evaluateExpressionTree(node->rLink);
    if (node->info == "+") return left + right;
    if (node->info == "-") return left - right;
    if (node->info == "*") return left * right;
    if (node->info == "/") return left / right;

    throw std::invalid_argument("Invalid operator");
}