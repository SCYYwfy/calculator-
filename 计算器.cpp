#include <iostream>  // ��������������������� cout �� cin���ṩ�˻���������������ܣ��������Ϣ������̨�ʹӿ���̨��ȡ�û����롣
#include <set>  // �ṩ�������� set ��֧�֣����ڴ洢ΨһԪ�صļ��ϣ��������е�Ԫ����Ψһ�ģ���������ظ�Ԫ�ء�
#include <string>  // ���ڴ����ַ���������洢�û�����ı��ʽ�ͼ���Ԫ�أ��ṩ���ַ����Ĵ洢�Ͳ������ܡ�
#include <sstream>  // �����ַ������������ɽ��ַ���ת��Ϊ�����������ͣ��罫����ļ���Ԫ���ַ���ת��Ϊ������ͨ�� istringstream �ཫ�ַ�������Ϊ�������������͡�
#include <stack>  // �ṩջ���������ڴ洢�������Ͳ�������ʵ�ֱ��ʽ��ֵ���㷨��ջ��ѭ����ȳ���LIFO��ԭ�򣬿����ڴ洢���ʽ�еĲ������Ͳ�������
#include <cctype>  // �ṩ�ַ����ຯ������ isdigit �����ж��ַ��Ƿ�Ϊ���֣����������������ַ��Ƿ�Ϊ�����ַ���
#include <cmath>  // �ṩ��ѧ�������� pow ���ڼ��������㣬sin��cos��tan �������Ǻ������㣬log ���ڼ���������ṩ�˷ḻ����ѧ���㹦�ܡ�
#include <cstdlib>  // �ṩͨ�õĹ��ߺ������� std::stoi ���ڽ��ַ���ת��Ϊ�������ɽ��ַ�����ʾ������ת��Ϊ�������͡�
#include <algorithm>  // �ṩ�㷨�������� set_union��set_intersection �� set_difference ���ڼ��ϲ������ɶԼ��Ͻ��в������������������
#include <iterator>  // �ṩ�����������ڱ������Ϻ��������� set ������Ԫ�ء�
#include <bitset>  // �ṩ bitset �࣬�ɽ�ʮ������ת��Ϊ�����Ʊ�ʾ��������ж����Ʊ�ʾ�Ͳ�����

using namespace std;//��������std�ռ�

#define PI 3.1415926  // ���峣�� Բ����PI�����ڽǶȺͻ��ȵ�ת��

// ��ʾ�˵�
// �������ܣ���ʾһ���������ּ���ѡ��Ĳ˵����û�ѡ��
// �����﷨���޲������޷���ֵ�������������Ϣ������̨
// ���ÿ⣺<iostream>
// ��ʹ�ú�����cout
void menu()
{
    cout << "-----------�๦�ܼ������˵�----------" << endl;
    cout << "0. ��������0������end��" << endl;
    cout << "1. ��������" << endl;
    cout << "2. �������ʽ��ֵ����" << endl;
    cout << "3. ����ת��" << endl;
    cout << "4. ���ӱ��ʽ��ֵ����" << endl;
    cout << "5. �Ƕ�ת�������Ǻ�������" << endl;
    cout << "-------------------------------------" << endl;
    cout << "���������ѡ��: ";
}


// �������㺯��
// ������������ Set1 �� Set2 �Լ��������� Ope_Type���Լ��Ͻ�����Ӧ�Ĳ���������������
// ������
// - Set1����һ������
// - Set2���ڶ�������
// - Ope_Type���������ͣ����������������
// ����ֵ�������ɹ����� 0������������Ч���� -1
int Set_Option(set<int>& Set1, set<int>& Set2, int Ope_Type)
{
    set<int> result;  // �洢��������Ľ��
    // ���弯�ϲ�����ö������
    enum Operation
    {
        Union_Set = 1,  // ��������
        Intersection = 2,  // ��������
        Diff_Set = 3  // �����
    };
    switch (Ope_Type)
    {
    case Union_Set:
        // ���㲢����������洢�� result ������
        set_union(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(result, result.begin()));
        break;
    case Intersection:
        // ���㽻����������洢�� result ������
        set_intersection(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(result, result.begin()));
        break;
    case Diff_Set:
        // ������Set1 - Set2����������洢�� result ������
        set_difference(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(result, result.begin()));
        break;
    default:
        cout << "��Ч�Ĳ�������" << endl;
        return -1;
    }
    // ����������
    cout << "-------------------------------------" << endl;
    cout << "������ϣ� ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


// �����������ж��ַ��Ƿ�Ϊ������
// ������
// - c�����жϵ��ַ�
// ����ֵ������ǲ��������� true�����򷵻� false
// ���ÿ⣺�޶���⣬ʹ�û������ַ��Ƚϲ���
bool isOperator(char c)
{
    // ����ַ��Ƿ�Ϊ�ӡ������ˡ�����˷������
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


// ������������ȡ�����������ȼ�
// ������
// - op��������
// ����ֵ�������������ȼ���^ Ϊ 3��* �� / Ϊ 2��+ �� - Ϊ 1������Ϊ 0
// ���ÿ⣺�޶���⣬ʹ�û������ַ��Ƚϲ���
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


// ����������ִ�ж�Ԫ����
// ������
// - a����һ��������
// - b���ڶ���������
// - op��������
// ����ֵ�����ݲ�����������Ӧ����Ľ��
// ���ÿ⣺<cmath>
// ��ʹ�ú�����pow
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;  // �ӷ�����
    case '-':
        return a - b;  // ��������
    case '*':
        return a * b;  // �˷�����
    case '/':
        return a / b;  // ��������
    case '^':
        // ʹ�� pow ��������������
        return pow(a, b);  // pow �������� <cmath> �⣬���� a �� b ����
    }
    return 0;
}


// ���������ʽ��ֵ����
// ��������������ʽ������ֵ
// ������
// - expression��������������ʽ�ַ���
// ����ֵ�����ʽ�ļ�����
// ���ÿ⣺<stack>��<cctype>��<cmath>
// ��ʹ�ú�������ֱ�ӵ��ÿ⺯����ʹ�� stack ��洢�������Ͳ�������ʹ�� isdigit �����ж��ַ��Ƿ�Ϊ���֣�ʹ�� applyOp �������в������ļ������
int evaluate(string expression)
{
    stack<int> operandStack;  // �洢��������ջ���洢����������ѭ LIFO ԭ��洢���ʽ�еĲ�����
    stack<char> operatorStack;  // �洢��������ջ���洢����������ѭ LIFO ԭ��洢���ʽ�еĲ�����

    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == ' ')
            continue;  // �����ո�

        if (isdigit(expression[i]))
        {
            int val = 0;
            // �������������ַ�ת��Ϊ����
            while (i < expression.length() && isdigit(expression[i]))
            {
                val = val * 10 + (expression[i] - '0');  // ���ַ�����ת��Ϊ�������������������ַ��������������
                i++;
            }
            i--;
            operandStack.push(val);  // ������ѹ�������ջ
        }
        else if (expression[i] == '(')
        {
            operatorStack.push(expression[i]);  // ��������ѹ�������ջ
        }
        else if (expression[i] == ')')
        {
            // ���������ڵ�����
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                int b = operandStack.top(); operandStack.pop();  // ���������� b
                int a = operandStack.top(); operandStack.pop();  // ���������� a
                char op = operatorStack.top(); operatorStack.pop();  // ����������
                operandStack.push(applyOp(a, b, op));  // ִ�в����������ѹ�������ջ
            }
            if (!operatorStack.empty())
                operatorStack.pop();  // ����������
        }
        else if (isOperator(expression[i]))
        {
            // ���ݲ����������ȼ���������
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(expression[i]))
            {
                int b = operandStack.top(); operandStack.pop();  // ���������� b
                int a = operandStack.top(); operandStack.pop();  // ���������� a
                char op = operatorStack.top(); operatorStack.pop();  // ����������
                operandStack.push(applyOp(a, b, op));  // ִ�в����������ѹ�������ջ
            }
            operatorStack.push(expression[i]);  // ����ǰ������ѹ�������ջ
        }
    }

    while (!operatorStack.empty())
    {
        int b = operandStack.top(); operandStack.pop();  // ���������� b
        int a = operandStack.top(); operandStack.pop();  // ���������� a
        char op = operatorStack.top(); operatorStack.pop();  // ����������
        operandStack.push(applyOp(a, b, op));  // ִ�в����������ѹ�������ջ
    }

    return operandStack.top();  // �������ս��
}

// ����ת������
// �������ܣ������û�ѡ����н���ת�����������������ơ��˽��ơ�ʮ��������ʮ����֮����໥ת��
// �����﷨���޲������޷���ֵ����Ҫ�����û������ͽ���ת������
// ���ÿ⣺<iostream>��<string>��<bitset>��<cstdlib>
// ��ʹ�ú�����cin��cout��stoi��bitset<32>::to_string��oct��hex
void baseConversion()
{
    int subChoice;
    cout << "-------------------------------------" << endl;
    cout << "1. �����ơ��˽��ơ�ʮ������תʮ����" << endl;
    cout << "2. ʮ����ת�����ơ��˽��ơ�ʮ������" << endl;
    cout << "��ѡ�����ת�����ͣ�";
    cin >> subChoice;
    cout << "-------------------------------------" << endl;
    if (subChoice == 1)
    {
        int baseChoice;
        cout << "1. ������" << endl;
        cout << "2. �˽���" << endl;
        cout << "3. ʮ������" << endl;
        cout << "��ѡ������Ľ��ƣ�";
        cin >> baseChoice;
        cout << "-------------------------------------" << endl;
        string numStr;
        cout << "������Ҫת�������֣�";
        cin >> numStr;
        int decimalResult;
        enum baseChoice
        {
            two=1,//������
            eight=2,//�˽���
            sixteen=3,//ʮ������
        };
        switch (baseChoice)
        {
        case two:
            // ���������ַ���ת��Ϊʮ���ƣ�ʹ�� std::stoi ����������������ָ������
            decimalResult = stoi(numStr, nullptr, 2);
            cout << "������ " << numStr << " ת��Ϊʮ����: " << decimalResult << endl;
            break;
        case eight:
            // ���˽����ַ���ת��Ϊʮ���ƣ�ʹ�� std::stoi ����������������ָ������
            decimalResult = stoi(numStr, nullptr, 8);
            cout << "�˽��� " << numStr << " ת��Ϊʮ����: " << decimalResult << endl;
            break;
        case sixteen:
            // ��ʮ�������ַ���ת��Ϊʮ���ƣ�ʹ�� std::stoi ����������������ָ������
            decimalResult = stoi(numStr, nullptr, 16);
            cout << "ʮ������ " << numStr << " ת��Ϊʮ����: " << decimalResult << endl;
            break;
        default:
            cout << "��Ч�Ľ���ѡ��" << endl;
            break;
        }
    }
    else if (subChoice == 2)
    {
        int num;
        cout << "-------------------------------------" << endl;
        cout << "������ʮ��������" << endl;
        cin >> num;
        cout << "-------------------------------------" << endl;
        int baseChoice;
        cout << "1. ������" << endl;
        cout << "2. �˽���" << endl;
        cout << "3. ʮ������" << endl;
        cout << "��ѡ��Ҫת����Ŀ����ƣ�";
        cin >> baseChoice;
        cout << "-------------------------------------" << endl;
        enum baseChoice
        {
            two = 1,//������
            eight = 2,//�˽���
            sixteen = 3,//ʮ������
        };
        switch (baseChoice)
        {
        case two:
            // ��ʮ������ת��Ϊ�����ƣ�ʹ�� bitset ��
            cout << "������: " << bitset<32>(num).to_string() << endl;
            break;
        case eight:
            // ��ʮ������ת��Ϊ�˽��ƣ�ʹ�� oct ���������ʽ
            cout << "�˽���: " << oct << num << endl;
            break;
        case sixteen:
            // ��ʮ������ת��Ϊʮ�����ƣ�ʹ�� hex ���������ʽ
            cout << "ʮ������: " << hex << num << endl;
            break;
        default:
            cout << "��Ч�Ľ���ѡ��" << endl;
            break;
        }
    }
    else
    {
        cout << "��Ч�Ľ���ת������ѡ��" << endl;
    }
}


// ���Ǻ������㺯��
// �������ܣ������û�ѡ�������Ӧ�����Ǻ���ֵ�����ҡ����ҡ����У�
// �����﷨���޲������޷���ֵ����Ҫ�����û����������Ǻ�������
// ���ÿ⣺<iostream>��<cmath>
// ��ʹ�ú�����cin��cout��sin��cos��tan
void trigonometricCalculation()
{
    int trigChoice;
    double angle;
    cout << "��ѡ�����Ǻ�����1. ���ң�2. ���ң�3. ����" << endl;
    cin >> trigChoice;  // ѡ�����Ǻ�������
    cout << "������Ƕȣ��Զ�Ϊ��λ����";
    cin >> angle;  // ����Ƕ�
    double radian = angle * PI / 180.0;  // ���Ƕ�ת��Ϊ����
    // ö�����ͣ����ڴ洢���Ǻ�����ѡ��
    enum trigChoice
    {
        sin_choice = 1,
        cos_choice = 2,
        tan_choice = 3
    };
    switch (trigChoice)
    {
    case sin_choice:
        // ���㲢�������ֵ��sin �������� <cmath> ��
        cout << "-------------------------------------" << endl;
        cout << "sin(" << angle << ") = " << sin(radian) << endl;
        break;
    case cos_choice:
        // ���㲢�������ֵ��cos �������� <cmath> ��
        cout << "-------------------------------------" << endl;
        cout << "cos(" << angle << ") = " << cos(radian) << endl;
        break;
    case tan_choice:
        // ���㲢�������ֵ��tan �������� <cmath> ��
        cout << "-------------------------------------" << endl;
        cout << "tan(" << angle << ") = " << tan(radian) << endl;
        break;
    default:
        cout << "-------------------------------------" << endl;
        cout << "��Ч��ѡ�������� 1��2 �� 3��" << endl;
        break;
    }
}

int main()
{
    cout << "                         ��������                 " << endl;
    cout << "    �����뻹�ڲ��ԣ��밴Ҫ��淶ʹ��              " << endl;
    cout << "��Ȼ�����������bug������Ա��Ϊ������ͷ������bug" << endl;
    // �������ܣ��������ڵ㣬ʵ�ֶ๦�ܼ������Ĳ˵������߼�
    // �������ܣ���Ϊ�������ڵ㣬ʵ�ֶ๦�ܼ������Ĳ˵������߼����û�����ͨ���˵�ѡ��ͬ�ļ��㹦�ܣ���������Ӧ�����ݽ��м��㡣
    // ���ÿ⣺<cmath>�����ڵ��� exp ������ȡ��Ȼ���� e �ľ�ȷֵ���Լ�ʹ�� log �������ж������㡣
    // ��ʹ�ú�����
    //    - exp(1)��������Ȼ���� e �ľ�ȷֵ��
    //    - log(num)�������� e Ϊ�׵Ķ�����
    //    - log(base)���ڼ����� base Ϊ�׵Ķ���ʱ����Ϊ���׹�ʽ��һ���֡�

    // ʹ�� exp(1) ����������Ȼ���� e �ľ�ȷֵ�����洢�ڱ��� e ��
    double e = exp(1);  // �� <cmath> ���У�ʹ�� exp(1) ��������ȡ��Ȼ�� e �ľ�ȷֵ
    // �洢�û��Ĳ˵�ѡ�񣬳�ʼ��Ϊ -1����ʾ�û���δ����ѡ��
    int choice = -1;  // �洢�û��Ĳ˵�ѡ�񣬴洢�û��Ӳ˵���ѡ��Ĳ���ѡ��
    // ���������־�����ڼ���Ԫ�����룬���û����� "end" ʱ������Ԫ�����������
    string over = "end";  // ���������־�����ڼ���Ԫ�����룬���ڱ�Ǽ���Ԫ������Ľ���
    // �洢���� 1 ��Ԫ�أ�ʹ�� set �����洢����֤Ԫ�ص�Ψһ�ԡ�
    set<int> Set1;  // �洢���� 1 ��Ԫ�أ��洢�û�����ļ��� 1 ��Ԫ��
    // �洢���� 2 ��Ԫ�أ�ʹ�� set �����洢����֤Ԫ�ص�Ψһ�ԡ�
    set<int> Set2;  // �洢���� 2 ��Ԫ�أ��洢�û�����ļ��� 2 ��Ԫ��
    // �������ѡ���ö�����ͣ����ڱ�ʾ��ͬ�ļ������
    enum option
    {
        quit,  // ���������û�ѡ���ѡ��ʱ�����˳�
        Set_Operation,  // �������㣬�û��ɶ��������Ͻ��в���������������
        Ari_Exp_Eva_Ope,  // ���������ʽ��ֵ���㣬�û�������һ���������ʽ���м���
        Base_Conversion,  // ����ת�����û��ɽ��в�ͬ���Ƽ��ת������
        Log_Calculation,  // ���� log���û�������һ�������͵����������
        Trigonometric_Calculation  // �������Ǻ������û�������ǶȽ������Ǻ�������
    };
    // ѭ����ʾ�˵���ֱ���û�ѡ���˳���choice == 0��
    while (choice != 0)
    {
        // ���� menu ������ʾ�˵���Ϊ�û��ṩ����ѡ�
        menu();  // ��ʾ�˵�
        // ��ȡ�û��Ĳ˵�ѡ��
        cin >> choice;  // ��ȡ�û�ѡ��
        switch (choice)
        {
        case Set_Operation:
        {
            // ���뼯�� 1 ��Ԫ�ص��߼�
            cout << "�����뼯�� 1 ��Ԫ�أ��� end ��������" << endl;
            string input;
            cin >> input;
            // ѭ�����뼯�� 1 ��Ԫ�أ�ֱ���û����� "end" ��������
            while (input != over)
            {
                int num;
                // ʹ�� istringstream �������ַ���ת��Ϊ����
                if (istringstream(input) >> num)  // �������ַ���ת��Ϊ����
                {
                    // ��ת�����������ӵ����� 1 ��
                    Set1.insert(num);  // ��������ӵ����� 1
                }
                else
                {
                    cout << "���벻�Ϸ��������������� end" << endl;
                }
                cin >> input;
            }
            cout << "-------------------------------------" << endl;
            // ���뼯�� 2 ��Ԫ�ص��߼�
            cout << "�����뼯�� 2 ��Ԫ�أ��� end ��������" << endl;
            cin >> input;
            // ѭ�����뼯�� 2 ��Ԫ�أ�ֱ���û����� "end" ��������
            while (input != over)
            {
                int num;
                // ʹ�� istringstream �������ַ���ת��Ϊ����
                if (istringstream(input) >> num)  // �������ַ���ת��Ϊ����
                {
                    // ��ת�����������ӵ����� 2 ��
                    Set2.insert(num);  // ��������ӵ����� 2
                }
                else
                {
                    cout << "���벻�Ϸ��������������� end" << endl;
                }
                cin >> input;
            }
            cout << "-------------------------------------" << endl;
            int Ope_Type;
            cout << "��ѡ���ǲ�����1����������2�������3����";
            cin >> Ope_Type;
            Set_Option(Set1, Set2, Ope_Type);  // ���ü������㺯��
            break;
        }
        case Ari_Exp_Eva_Ope:
        {
            cout << "-------------------------------------" << endl;
            cout << "�������������ʽ�����س���������" << endl;
            string expression;
            // ����֮ǰ�� cin >> choice ������һ�����з�����Ҫ�����һ�� getline ����ȡ�������ʽ
            getline(cin, expression);
            getline(cin, expression);
            int result = evaluate(expression);  
            // ���� evaluate �����Ա��ʽ��ֵ����������洢�� result ��
            cout << "-------------------------------------" << endl;
            cout << "���: " << result << endl;
            break;
        }
        case Base_Conversion:
        {
            // ���� baseConversion �������н���ת������
            baseConversion(); 
            break;
        }
        case Log_Calculation:
        {
            double num, base;
            cout << "-------------------------------------" << endl;
            cout << "������һ���������ڼ��� log��������������������������" << endl;
            cin >> num;  // ��������Ĳ�����������
            cout << "����������ĵ�����" << endl;
            cin >> base;  // ��������ĵ���
            // ��������Ƿ�Ϸ�������������������� 0������������� 0 �Ҳ�Ϊ 1
            if (num > 0 && base > 0 && base != 1)
            {
                // ʹ�û��׹�ʽ log(num) / log(base) ������ base Ϊ�� num �Ķ�������������
                cout << "-------------------------------------" << endl;
                cout << "log_" << base << "(" << num << ") = " << log(num) / log(base) << endl;
            }
            else
            {
                cout << "���벻�Ϸ��������������ҵ�����Ϊ 1��" << endl;
            }
            break;
        }
        case Trigonometric_Calculation:
        {
            // ���� trigonometricCalculation �����������Ǻ�������
            trigonometricCalculation(); 
            break;
        }
        }
    }
    return 0;
}