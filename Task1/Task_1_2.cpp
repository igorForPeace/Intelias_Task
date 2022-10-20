#include <iostream>
#define SET_BIT(x, p) ((x) |= (1 << (p)))
#define CLR_BIT(x, p) ((x) &= ~(1 << (p)))
#define TGL_BIT(x, p) ((x)^=(1<<(p)))
#define CHK_BIT(x, p) (((x) & (1<<(p))) > 0? 1: 0)

void Int2BitStr(int, int);

int main()
{
    //������� ���������� ��� ��������
    std::cout << "First output without changing :\n";
    int a = 234;
    std::cout << a << std::endl; //����� ���������� � � ���������� �������
    Int2BitStr(a, sizeof(a) * 8); //������� ����� � �������� �������

    std::cout << "Example with SET_BIT: \n";
    SET_BIT(a, 2); //������, ������� ������������� ��� � �������, ���������� ������ ����������
    std::cout << a << std::endl; 
    Int2BitStr(a, sizeof(a) * 8);

    std::cout << "Example with CLR_BIT: \n";
    CLR_BIT(a, 1); //������, ������� ������������� 0 � �������, ������� �������� ������ ����������
    std::cout << a << std::endl;
    Int2BitStr(a, sizeof(a) * 8);

    std::cout << "Example with TGL_BIT: \n";
    TGL_BIT(a, 6); //������, ������� "�����������" ��� � ������ �������
    std::cout << a << std::endl;
    Int2BitStr(a, sizeof(a) * 8);

    std::cout << "Example with CHK_BIT: \n";
    std::cout << "CHK_BIT(a, 1) = "<< CHK_BIT(a, 1)<<std::endl; //������, ������� ���������� �������� ����, ������� ��������� �� �������� �������
    std::cout << "CHK_BIT(a, 3) = " << CHK_BIT(a, 3) << std::endl;
}

void Int2BitStr(int x, int size)
{
    int i;
    char* bin = new char[size];
    std::cout << "0b";
    for (i = size - 1; i >= 0; --i)
    {
        if (!((i + 1) % 8))
            std::cout << ' ';
        std::cout << (bin[i] = ((x >> i) & 1) + 48);
    }
    std::cout << std::endl;
    delete[] bin;
}