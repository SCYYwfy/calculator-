#include <iostream>  // 用于输入输出操作，例如 cout 和 cin，提供了基本的输入输出功能，如输出信息到控制台和从控制台读取用户输入。
#include <set>  // 提供集合容器 set 的支持，用于存储唯一元素的集合，，集合中的元素是唯一的，不会出现重复元素。
#include <string>  // 用于处理字符串，例如存储用户输入的表达式和集合元素，提供了字符串的存储和操作功能。
#include <sstream>  // 用于字符串流操作，可将字符串转换为其他数据类型，如将输入的集合元素字符串转换为整数，通过 istringstream 类将字符串解析为整数等数据类型。
#include <stack>  // 提供栈容器，用于存储操作数和操作符，实现表达式求值的算法，栈遵循后进先出（LIFO）原则，可用于存储表达式中的操作数和操作符。
#include <cctype>  // 提供字符分类函数，如 isdigit 用于判断字符是否为数字，可用于区分输入字符是否为数字字符。
#include <cmath>  // 提供数学函数，如 pow 用于计算幂运算，sin、cos、tan 用于三角函数计算，log 用于计算对数，提供了丰富的数学计算功能。
#include <cstdlib>  // 提供通用的工具函数，如 std::stoi 用于将字符串转换为整数，可将字符串表示的数字转换为整数类型。
#include <algorithm>  // 提供算法函数，如 set_union、set_intersection 和 set_difference 用于集合操作，可对集合进行并集、交集、差集操作。
#include <iterator>  // 提供迭代器，用于遍历集合和容器，如 set 容器的元素。
#include <bitset>  // 提供 bitset 类，可将十进制数转换为二进制表示，方便进行二进制表示和操作。

using namespace std;//声明调用std空间

#define PI 3.1415926  // 定义常量 圆周率PI，用于角度和弧度的转换

// 显示菜单
// 函数功能：显示一个包含多种计算选项的菜单供用户选择
// 函数语法：无参数，无返回值，仅用于输出信息到控制台
// 调用库：<iostream>
// 库使用函数：cout
void menu()
{
    cout << "-----------多功能计算器菜单----------" << endl;
    cout << "0. 结束（点0或输入end）" << endl;
    cout << "1. 集合运算" << endl;
    cout << "2. 算术表达式求值运算" << endl;
    cout << "3. 进制转换" << endl;
    cout << "4. 复杂表达式求值运算" << endl;
    cout << "5. 角度转换、三角函数计算" << endl;
    cout << "-------------------------------------" << endl;
    cout << "请输入你的选择: ";
}


// 集合运算函数
// 接收两个集合 Set1 和 Set2 以及操作类型 Ope_Type，对集合进行相应的操作并输出结果集合
// 参数：
// - Set1：第一个集合
// - Set2：第二个集合
// - Ope_Type：操作类型（并集、交集、差集）
// 返回值：操作成功返回 0，操作类型无效返回 -1
int Set_Option(set<int>& Set1, set<int>& Set2, int Ope_Type)
{
    set<int> result;  // 存储集合运算的结果
    // 定义集合操作的枚举类型
    enum Operation
    {
        Union_Set = 1,  // 并集操作
        Intersection = 2,  // 交集操作
        Diff_Set = 3  // 差集操作
    };
    switch (Ope_Type)
    {
    case Union_Set:
        // 计算并集，将结果存储在 result 集合中
        set_union(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(result, result.begin()));
        break;
    case Intersection:
        // 计算交集，将结果存储在 result 集合中
        set_intersection(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(result, result.begin()));
        break;
    case Diff_Set:
        // 计算差集（Set1 - Set2），将结果存储在 result 集合中
        set_difference(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(result, result.begin()));
        break;
    default:
        cout << "无效的操作类型" << endl;
        return -1;
    }
    // 输出结果集合
    cout << "-------------------------------------" << endl;
    cout << "结果集合： ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


// 辅助函数：判断字符是否为操作符
// 参数：
// - c：待判断的字符
// 返回值：如果是操作符返回 true，否则返回 false
// 调用库：无额外库，使用基本的字符比较操作
bool isOperator(char c)
{
    // 检查字符是否为加、减、乘、除或乘方运算符
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


// 辅助函数：获取操作符的优先级
// 参数：
// - op：操作符
// 返回值：操作符的优先级，^ 为 3，* 和 / 为 2，+ 和 - 为 1，其他为 0
// 调用库：无额外库，使用基本的字符比较操作
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


// 辅助函数：执行二元运算
// 参数：
// - a：第一个操作数
// - b：第二个操作数
// - op：操作符
// 返回值：根据操作符进行相应运算的结果
// 调用库：<cmath>
// 库使用函数：pow
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;  // 加法运算
    case '-':
        return a - b;  // 减法运算
    case '*':
        return a * b;  // 乘法运算
    case '/':
        return a / b;  // 除法运算
    case '^':
        // 使用 pow 函数计算幂运算
        return pow(a, b);  // pow 函数来自 <cmath> 库，计算 a 的 b 次幂
    }
    return 0;
}


// 简单算术表达式求值函数
// 对输入的算术表达式进行求值
// 参数：
// - expression：输入的算术表达式字符串
// 返回值：表达式的计算结果
// 调用库：<stack>、<cctype>、<cmath>
// 库使用函数：无直接调用库函数，使用 stack 类存储操作数和操作符，使用 isdigit 函数判断字符是否为数字，使用 applyOp 函数进行操作符的计算操作
int evaluate(string expression)
{
    stack<int> operandStack;  // 存储操作数的栈，存储操作数，遵循 LIFO 原则存储表达式中的操作数
    stack<char> operatorStack;  // 存储操作符的栈，存储操作符，遵循 LIFO 原则存储表达式中的操作符

    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == ' ')
            continue;  // 跳过空格

        if (isdigit(expression[i]))
        {
            int val = 0;
            // 将连续的数字字符转换为整数
            while (i < expression.length() && isdigit(expression[i]))
            {
                val = val * 10 + (expression[i] - '0');  // 将字符数字转换为整数，将连续的数字字符组成完整的整数
                i++;
            }
            i--;
            operandStack.push(val);  // 将数字压入操作数栈
        }
        else if (expression[i] == '(')
        {
            operatorStack.push(expression[i]);  // 将左括号压入操作符栈
        }
        else if (expression[i] == ')')
        {
            // 处理括号内的运算
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                int b = operandStack.top(); operandStack.pop();  // 弹出操作数 b
                int a = operandStack.top(); operandStack.pop();  // 弹出操作数 a
                char op = operatorStack.top(); operatorStack.pop();  // 弹出操作符
                operandStack.push(applyOp(a, b, op));  // 执行操作并将结果压入操作数栈
            }
            if (!operatorStack.empty())
                operatorStack.pop();  // 弹出左括号
        }
        else if (isOperator(expression[i]))
        {
            // 根据操作符的优先级处理运算
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(expression[i]))
            {
                int b = operandStack.top(); operandStack.pop();  // 弹出操作数 b
                int a = operandStack.top(); operandStack.pop();  // 弹出操作数 a
                char op = operatorStack.top(); operatorStack.pop();  // 弹出操作符
                operandStack.push(applyOp(a, b, op));  // 执行操作并将结果压入操作数栈
            }
            operatorStack.push(expression[i]);  // 将当前操作符压入操作符栈
        }
    }

    while (!operatorStack.empty())
    {
        int b = operandStack.top(); operandStack.pop();  // 弹出操作数 b
        int a = operandStack.top(); operandStack.pop();  // 弹出操作数 a
        char op = operatorStack.top(); operatorStack.pop();  // 弹出操作符
        operandStack.push(applyOp(a, b, op));  // 执行操作并将结果压入操作数栈
    }

    return operandStack.top();  // 返回最终结果
}

// 进制转换函数
// 函数功能：根据用户选择进行进制转换操作，包括二进制、八进制、十六进制与十进制之间的相互转换
// 函数语法：无参数，无返回值，主要用于用户交互和进制转换操作
// 调用库：<iostream>、<string>、<bitset>、<cstdlib>
// 库使用函数：cin、cout、stoi、bitset<32>::to_string、oct、hex
void baseConversion()
{
    int subChoice;
    cout << "-------------------------------------" << endl;
    cout << "1. 二进制、八进制、十六进制转十进制" << endl;
    cout << "2. 十进制转二进制、八进制、十六进制" << endl;
    cout << "请选择进制转换类型：";
    cin >> subChoice;
    cout << "-------------------------------------" << endl;
    if (subChoice == 1)
    {
        int baseChoice;
        cout << "1. 二进制" << endl;
        cout << "2. 八进制" << endl;
        cout << "3. 十六进制" << endl;
        cout << "请选择输入的进制：";
        cin >> baseChoice;
        cout << "-------------------------------------" << endl;
        string numStr;
        cout << "请输入要转换的数字：";
        cin >> numStr;
        int decimalResult;
        enum baseChoice
        {
            two=1,//二进制
            eight=2,//八进制
            sixteen=3,//十六进制
        };
        switch (baseChoice)
        {
        case two:
            // 将二进制字符串转换为十进制，使用 std::stoi 函数，第三个参数指定进制
            decimalResult = stoi(numStr, nullptr, 2);
            cout << "二进制 " << numStr << " 转换为十进制: " << decimalResult << endl;
            break;
        case eight:
            // 将八进制字符串转换为十进制，使用 std::stoi 函数，第三个参数指定进制
            decimalResult = stoi(numStr, nullptr, 8);
            cout << "八进制 " << numStr << " 转换为十进制: " << decimalResult << endl;
            break;
        case sixteen:
            // 将十六进制字符串转换为十进制，使用 std::stoi 函数，第三个参数指定进制
            decimalResult = stoi(numStr, nullptr, 16);
            cout << "十六进制 " << numStr << " 转换为十进制: " << decimalResult << endl;
            break;
        default:
            cout << "无效的进制选择" << endl;
            break;
        }
    }
    else if (subChoice == 2)
    {
        int num;
        cout << "-------------------------------------" << endl;
        cout << "请输入十进制数：" << endl;
        cin >> num;
        cout << "-------------------------------------" << endl;
        int baseChoice;
        cout << "1. 二进制" << endl;
        cout << "2. 八进制" << endl;
        cout << "3. 十六进制" << endl;
        cout << "请选择要转换的目标进制：";
        cin >> baseChoice;
        cout << "-------------------------------------" << endl;
        enum baseChoice
        {
            two = 1,//二进制
            eight = 2,//八进制
            sixteen = 3,//十六进制
        };
        switch (baseChoice)
        {
        case two:
            // 将十进制数转换为二进制，使用 bitset 类
            cout << "二进制: " << bitset<32>(num).to_string() << endl;
            break;
        case eight:
            // 将十进制数转换为八进制，使用 oct 控制输出格式
            cout << "八进制: " << oct << num << endl;
            break;
        case sixteen:
            // 将十进制数转换为十六进制，使用 hex 控制输出格式
            cout << "十六进制: " << hex << num << endl;
            break;
        default:
            cout << "无效的进制选择" << endl;
            break;
        }
    }
    else
    {
        cout << "无效的进制转换类型选择" << endl;
    }
}


// 三角函数计算函数
// 函数功能：根据用户选择计算相应的三角函数值（正弦、余弦、正切）
// 函数语法：无参数，无返回值，主要用于用户交互和三角函数计算
// 调用库：<iostream>、<cmath>
// 库使用函数：cin、cout、sin、cos、tan
void trigonometricCalculation()
{
    int trigChoice;
    double angle;
    cout << "请选择三角函数：1. 正弦，2. 余弦，3. 正切" << endl;
    cin >> trigChoice;  // 选择三角函数类型
    cout << "请输入角度（以度为单位）：";
    cin >> angle;  // 输入角度
    double radian = angle * PI / 180.0;  // 将角度转换为弧度
    // 枚举类型，用于存储三角函数的选择
    enum trigChoice
    {
        sin_choice = 1,
        cos_choice = 2,
        tan_choice = 3
    };
    switch (trigChoice)
    {
    case sin_choice:
        // 计算并输出正弦值，sin 函数来自 <cmath> 库
        cout << "-------------------------------------" << endl;
        cout << "sin(" << angle << ") = " << sin(radian) << endl;
        break;
    case cos_choice:
        // 计算并输出余弦值，cos 函数来自 <cmath> 库
        cout << "-------------------------------------" << endl;
        cout << "cos(" << angle << ") = " << cos(radian) << endl;
        break;
    case tan_choice:
        // 计算并输出正切值，tan 函数来自 <cmath> 库
        cout << "-------------------------------------" << endl;
        cout << "tan(" << angle << ") = " << tan(radian) << endl;
        break;
    default:
        cout << "-------------------------------------" << endl;
        cout << "无效的选择，请输入 1、2 或 3。" << endl;
        break;
    }
}

int main()
{
    cout << "                         保命声明                 " << endl;
    cout << "    本代码还在测试，请按要求规范使用              " << endl;
    cout << "当然，你整活出了bug，程序员会为你掉多点头发来改bug" << endl;
    // 函数功能：程序的入口点，实现多功能计算器的菜单驱动逻辑
    // 函数功能：作为程序的入口点，实现多功能计算器的菜单驱动逻辑，用户可以通过菜单选择不同的计算功能，并输入相应的数据进行计算。
    // 调用库：<cmath>，用于调用 exp 函数获取自然常数 e 的精确值，以及使用 log 函数进行对数计算。
    // 库使用函数：
    //    - exp(1)：计算自然常数 e 的精确值。
    //    - log(num)：计算以 e 为底的对数。
    //    - log(base)：在计算以 base 为底的对数时，作为换底公式的一部分。

    // 使用 exp(1) 函数计算自然常数 e 的精确值，并存储在变量 e 中
    double e = exp(1);  // 在 <cmath> 库中，使用 exp(1) 函数来获取自然数 e 的精确值
    // 存储用户的菜单选择，初始化为 -1，表示用户尚未做出选择。
    int choice = -1;  // 存储用户的菜单选择，存储用户从菜单中选择的操作选项
    // 输入结束标志，用于集合元素输入，当用户输入 "end" 时，集合元素输入结束。
    string over = "end";  // 输入结束标志，用于集合元素输入，用于标记集合元素输入的结束
    // 存储集合 1 的元素，使用 set 容器存储，保证元素的唯一性。
    set<int> Set1;  // 存储集合 1 的元素，存储用户输入的集合 1 的元素
    // 存储集合 2 的元素，使用 set 容器存储，保证元素的唯一性。
    set<int> Set2;  // 存储集合 2 的元素，存储用户输入的集合 2 的元素
    // 定义操作选项的枚举类型，用于表示不同的计算操作
    enum option
    {
        quit,  // 结束程序，用户选择此选项时程序将退出
        Set_Operation,  // 集合运算，用户可对两个集合进行并集、交集或差集运算
        Ari_Exp_Eva_Ope,  // 简单算术表达式求值运算，用户可输入一个算术表达式进行计算
        Base_Conversion,  // 进制转换，用户可进行不同进制间的转换操作
        Log_Calculation,  // 计算 log，用户可输入一个正数和底数计算对数
        Trigonometric_Calculation  // 计算三角函数，用户可输入角度进行三角函数计算
    };
    // 循环显示菜单，直到用户选择退出（choice == 0）
    while (choice != 0)
    {
        // 调用 menu 函数显示菜单，为用户提供操作选项。
        menu();  // 显示菜单
        // 获取用户的菜单选择
        cin >> choice;  // 获取用户选择
        switch (choice)
        {
        case Set_Operation:
        {
            // 输入集合 1 的元素的逻辑
            cout << "请输入集合 1 的元素，按 end 结束输入" << endl;
            string input;
            cin >> input;
            // 循环输入集合 1 的元素，直到用户输入 "end" 结束输入
            while (input != over)
            {
                int num;
                // 使用 istringstream 将输入字符串转换为整数
                if (istringstream(input) >> num)  // 将输入字符串转换为整数
                {
                    // 将转换后的整数添加到集合 1 中
                    Set1.insert(num);  // 将整数添加到集合 1
                }
                else
                {
                    cout << "输入不合法，请输入整数或 end" << endl;
                }
                cin >> input;
            }
            cout << "-------------------------------------" << endl;
            // 输入集合 2 的元素的逻辑
            cout << "请输入集合 2 的元素，按 end 结束输入" << endl;
            cin >> input;
            // 循环输入集合 2 的元素，直到用户输入 "end" 结束输入
            while (input != over)
            {
                int num;
                // 使用 istringstream 将输入字符串转换为整数
                if (istringstream(input) >> num)  // 将输入字符串转换为整数
                {
                    // 将转换后的整数添加到集合 2 中
                    Set2.insert(num);  // 将整数添加到集合 2
                }
                else
                {
                    cout << "输入不合法，请输入整数或 end" << endl;
                }
                cin >> input;
            }
            cout << "-------------------------------------" << endl;
            int Ope_Type;
            cout << "请选择是并集（1），交集（2），差集（3）：";
            cin >> Ope_Type;
            Set_Option(Set1, Set2, Ope_Type);  // 调用集合运算函数
            break;
        }
        case Ari_Exp_Eva_Ope:
        {
            cout << "-------------------------------------" << endl;
            cout << "请输入算术表达式，按回车结束输入" << endl;
            string expression;
            // 由于之前的 cin >> choice 会留下一个换行符，需要多调用一次 getline 来读取完整表达式
            getline(cin, expression);
            getline(cin, expression);
            int result = evaluate(expression);  
            // 调用 evaluate 函数对表达式求值，并将结果存储在 result 中
            cout << "-------------------------------------" << endl;
            cout << "结果: " << result << endl;
            break;
        }
        case Base_Conversion:
        {
            // 调用 baseConversion 函数进行进制转换操作
            baseConversion(); 
            break;
        }
        case Log_Calculation:
        {
            double num, base;
            cout << "-------------------------------------" << endl;
            cout << "请输入一个正数用于计算 log（先输入对数，后输入底数）：" << endl;
            cin >> num;  // 输入对数的参数，即真数
            cout << "请输入对数的底数：" << endl;
            cin >> base;  // 输入对数的底数
            // 检查输入是否合法，对数的真数必须大于 0，底数必须大于 0 且不为 1
            if (num > 0 && base > 0 && base != 1)
            {
                // 使用换底公式 log(num) / log(base) 计算以 base 为底 num 的对数，并输出结果
                cout << "-------------------------------------" << endl;
                cout << "log_" << base << "(" << num << ") = " << log(num) / log(base) << endl;
            }
            else
            {
                cout << "输入不合法，请输入正数且底数不为 1。" << endl;
            }
            break;
        }
        case Trigonometric_Calculation:
        {
            // 调用 trigonometricCalculation 函数进行三角函数计算
            trigonometricCalculation(); 
            break;
        }
        }
    }
    return 0;
}