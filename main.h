#pragma once

int main() {
    std::ifstream infile("RpnData.txt");
    if (!infile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string expression;
    while (std::getline(infile, expression)) {
        binaryExpressionTree exprTree;
        exprTree.buildExpressionTree(expression);
        double result = exprTree.evaluateExpressionTree();
        std::cout << "Expression: " << expression << "\nResult: " << result << std::endl;
    }

    infile.close();
    return 0;
}
