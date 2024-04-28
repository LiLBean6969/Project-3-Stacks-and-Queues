#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
/*
Roberto Velazquez
CWID:885666107
*/

class Stack {
private:
    std::stack<char> st;

public:
    void validPara(std::string expr) {
        int balance = 0;
        for (char c : expr) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                balance++;
            } else if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) {
                    std::cout << "invalid" << std::endl;
                    return;
                }
                char top = st.top();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    std::cout << "invalid" << std::endl;
                    return;
                }
                st.pop();
                balance--;
            }
        }
        if (balance == 0) {
            std::cout << "valid" << std::endl;
        } else {
            std::cout << "invalid" << std::endl;
        }
    }

    int indexError(std::string expr) {
        std::stack<int> indices;
        for (int i = 0; i < expr.length(); i++) {
            if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
                indices.push(i);
            } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
                if (indices.empty()) {
                    return i;
                }
                indices.pop();
            }
        }
        return indices.empty() ? -1 : indices.top();
    }

    void minPara(std::string expr) {
        int balance = 0;
        for (char c : expr) {
            if (c == '(' || c == '[' || c == '{') {
                balance++;
            } else if (c == ')' || c == ']' || c == '}') {
                if (balance > 0) {
                    balance--;
                }
            }
        }
        std::cout << balance << std::endl;
    }

    void scorePara(std::string expr) {
        int score = 0;
        for (int i = 0; i < expr.length(); i++) {
            if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
                int j = i + 1;
                int open = 1;
                while (open != 0 && j < expr.length()) {
                    if (expr[j] == '(' || expr[j] == '[' || expr[j] == '{') {
                        open++;
                    } else if (expr[j] == ')' || expr[j] == ']' || expr[j] == '}') {
                        open--;
                    }
                    j++;
                }
                if (open == 0) {
                    score++;
                }
            }
        }
        std::cout << score << std::endl;
    }
};

class Queue {
private:
    std::queue<std::string> q;

public:
    void enqueue(std::string message) {
        for (int i = 0; i < message.length(); i += 8) {
            std::string chunk = message.substr(i, 8);
            std::reverse(chunk.begin(), chunk.end());
            q.push(chunk);
        }
    }

    void processMsg() {
        std::string fullMsg = "";
        while (!q.empty()) {
            std::string chunk = q.front();
            std::reverse(chunk.begin(), chunk.end());
            fullMsg += chunk;
            q.pop();
        }
        std::cout << fullMsg << std::endl;
    }
};

int main(){
Stack s1;
s1.validPara("(([]))");
s1.minPara("(([]))");
s1.scorePara("(([]))");
s1.validPara("(([])");
std::cout<<s1.indexError("(([))")<<std::endl;
s1.minPara("(([])");
s1.validPara("(([{}))");
std::cout<<s1.indexError("(([[}])")<<std::endl;
s1.minPara("(([{}))");
s1.scorePara("(([{}))");
std::cout<<s1.indexError("({}[]()[)")<<std::endl;
s1.validPara("(([))");
s1.minPara("(([))");
std::cout<<s1.indexError("[({)]")<<std::endl;
s1.validPara("(([{[{({})}]}]))");
s1.minPara("(([{[{({})}]}]))");
s1.scorePara("(([{[{({})}]}]))");
s1.validPara("(([[{[{({})}]))");
s1.validPara("(([[{[{({})}]}])]))");
s1.scorePara("(([[{[{({})}]}])]))");
std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
s1.validPara("(())");
s1.validPara("(())");
s1.validPara("void function(){}");
s1.scorePara("void function(){}");
s1.validPara("void function(");
s1.minPara("void function(");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;
Queue q1;
q1.enqueue("This is a secure message.");
q1.processMsg();
q1.enqueue("The product I received is damaged. What should I do?");
q1.processMsg();
q1.enqueue("I need assistance with setting up my new device");
q1.processMsg();
q1.enqueue("The website is not loading properly on my browser.");
q1.processMsg();
q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
q1.processMsg();
q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
q1.processMsg();
q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
q1.processMsg();
q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
q1.processMsg();
return 0;
}
