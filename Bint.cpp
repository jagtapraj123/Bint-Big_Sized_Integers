#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define PART_MAX 999999999

struct int_part
{
    int num;
    int_part *next_part, *prev_part;
    int_part(int n)
    {
        this->num = n;
        next_part = prev_part = NULL;
    }
};

class bint
{
private:
    int_part *lsp;
    int_part *msp;
    bool negative = false;

    int conv_digit(char n)
    {
        if (n == '0')
            return 0;
        else if (n == '1')
            return 1;
        else if (n == '2')
            return 2;
        else if (n == '3')
            return 3;
        else if (n == '4')
            return 4;
        else if (n == '5')
            return 5;
        else if (n == '6')
            return 6;
        else if (n == '7')
            return 7;
        else if (n == '8')
            return 8;
        else if (n == '9')
            return 9;
        return -1;
    }

    void modify_part(int i, int val)
    {
        if (i >= 0)
        {
            int_part *part_loc = lsp;
            for (int j = 0; j < i; j++)
            {
                part_loc = part_loc->next_part;
            }

            part_loc->num = val;
        }
        else if (i < 0)
        {
            int_part *part_loc = msp;
            for (int j = -1; j > i; j--)
            {
                part_loc = part_loc->prev_part;
            }

            part_loc->num = val;
        }
    }

    void make_part(int val)
    {
        int_part *temp = new int_part(val);
        msp->next_part = temp;
        temp->prev_part = msp;
        msp = temp;
    }

    int get_size_from(int_part *start)
    {
        if (start == NULL)
        {
            return 0;
        }
        return 1 + get_size_from(start->next_part);
    }

    int get_part_from(int i, int_part *start)
    {
        if (start == NULL)
        {
            return 0;
        }

        if (i == 0)
        {
            return start->num;
        }
        else if (i > 0)
        {
            return get_part_from(i - 1, start->next_part);
        }
        else
        {
            return get_part_from(i + 1, start->prev_part);
        }
    }

public:
    bint(long long int n)
    {
        string str_n = to_string(n);
        if (str_n[0] == '-')
        {
            negative = true;
            str_n = str_n.substr(1);
        }

        int k = str_n.length() / 9;

        int part;
        for (int cs = 0; cs < k; cs++)
        {
            part = 0;
            for (int i = (str_n.length() - ((cs + 1) * 9)); i < (str_n.length() - (cs * 9)); i++)
            {
                char temp = str_n[i];
                part = (part * 10) + conv_digit(temp);
            }
            if (cs == 0)
            {
                lsp = new int_part(part);
                msp = lsp;
            }
            else
            {
                int_part *temp = new int_part(part);
                msp->next_part = temp;
                temp->prev_part = msp;
                msp = temp;
            }
        }
        if (str_n.length() % 9 != 0)
        {
            part = 0;
            for (int i = 0; i < (str_n.length() - (k * 9)); i++)
            {
                char temp = str_n[i];
                part = (part * 10) + conv_digit(temp);
            }
            if (k == 0)
            {
                lsp = new int_part(part);
                msp = lsp;
            }
            else
            {
                int_part *temp = new int_part(part);
                msp->next_part = temp;
                temp->prev_part = msp;
                msp = temp;
            }
        }
    }

    bint(string str_n)
    {
        if (str_n[0] == '-')
        {
            negative = true;
            str_n = str_n.substr(1);
        }

        int k = str_n.length() / 9;

        int part;
        for (int cs = 0; cs < k; cs++)
        {
            part = 0;
            for (int i = (str_n.length() - ((cs + 1) * 9)); i < (str_n.length() - (cs * 9)); i++)
            {
                char temp = str_n[i];
                part = (part * 10) + conv_digit(temp);
            }
            if (cs == 0)
            {
                lsp = new int_part(part);
                msp = lsp;
            }
            else
            {
                int_part *temp = new int_part(part);
                msp->next_part = temp;
                temp->prev_part = msp;
                msp = temp;
            }
        }
        if (str_n.length() % 9 != 0)
        {
            part = 0;
            for (int i = 0; i < (str_n.length() - (k * 9)); i++)
            {
                char temp = str_n[i];
                part = (part * 10) + conv_digit(temp);
            }
            if (k == 0)
            {
                lsp = new int_part(part);
                msp = lsp;
            }
            else
            {
                int_part *temp = new int_part(part);
                msp->next_part = temp;
                temp->prev_part = msp;
                msp = temp;
            }
        }
    }

    void printpart(int_part *part)
    {
        if (part == NULL)
        {
            return;
        }
        int n = part->num;
        string num = "";

        for (int i = 0; i < 9; i++)
        {
            num = to_string(n % 10) + num;
            n /= 10;
        }

        cout << num;

        printpart(part->prev_part);
    }

    void print()
    {
        if (negative)
        {
            cout << '-';
        }

        cout << msp->num;
        printpart(msp->prev_part);
        cout << endl;
    }

    int get_size()
    {
        return get_size_from(lsp);
    }

    int get_part(int i)
    {
        if (i >= 0)
        {
            return get_part_from(i, lsp);
        }
        else
        {
            return get_part_from(i + 1, msp);
        }
    }

    bint copy()
    {
        int size_n = get_size();
        bint cp = bint(get_part(0));
        for (int i = 1; i < size_n; i++)
        {
            cp.make_part(get_part(i));
        }

        return cp;
    }

    // void operator=(bint m){
    //     lsp->next_part = NULL;
    //     msp = lsp;
    //     int size_m = m.get_size();
    //     for (int i = 0; i < size_m; i++)
    //     {
    //         make_part(m.get_part(i));
    //     }
    // }

    // void operator=(long long int m){
    //     operator=(bint(m));
    // }

    // void operator=(string str_m){
    //     operator=(bint(str_m));
    // }

    bint operator+(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        bint sum = bint(0);

        int carry = 0;
        if (!negative && !m.negative)
        {
            long long int part_sum;
            for (int i = 0; i < max(size_n, size_m); i++)
            {
                part_sum = get_part(i) + m.get_part(i) + carry;
                carry = 0;
                if (i == 0)
                {
                    if (part_sum > PART_MAX)
                    {
                        sum.modify_part(i, part_sum % (PART_MAX + 1));
                        carry = part_sum / (PART_MAX + 1);
                    }
                    else
                    {
                        sum.modify_part(i, part_sum);
                    }
                }
                else
                {
                    if (part_sum > PART_MAX)
                    {
                        sum.make_part(part_sum % (PART_MAX + 1));
                        carry = part_sum / (PART_MAX + 1);
                    }
                    else
                    {
                        sum.make_part(part_sum);
                    }
                }
            }

            if (carry != 0)
            {
                sum.make_part(carry);
            }
        }
        else if (negative && m.negative)
        {
            negative = false;
            m.negative = false;

            sum = operator+(m);
            sum.negative = true;

            negative = true;
            m.negative = true;
        }
        else if (!negative && m.negative)
        {
            m.negative = false;

            sum = operator-(m);

            m.negative = true;
        }
        else if (negative && !m.negative)
        {
            negative = false;

            sum = operator-(m);
            sum.negative = !sum.negative;

            negative = true;
        }
        return sum;
    }

    bint operator+(long long int m)
    {
        return operator+(bint(m));
    }

    bint operator+(string str_m)
    {
        return operator+(bint(str_m));
    }

    bint operator++()
    {
        int size_n = get_size();
        long long int part;
        int carry = 1;
        if (!negative)
        {
            for (int i = 0; i < size_n; i++)
            {
                part = (long long int)get_part(i);
                ++part;
                modify_part(i, part % (PART_MAX + 1));
                carry = (int)part / (PART_MAX + 1);
                if (carry == 0)
                {
                    break;
                }
            }
            if (carry == 1)
            {
                make_part(carry);
            }
        }
        else
        {
            negative = false;
            operator--();
            negative = true;
        }
        return copy();
    }

    bint operator++(int)
    {
        bint cp = copy();
        int size_n = get_size();
        long long int part;
        int carry = 1;
        if (!negative)
        {
            for (int i = 0; i < size_n; i++)
            {
                part = (long long int)get_part(i);
                ++part;
                modify_part(i, part % (PART_MAX + 1));
                carry = (int)part / (PART_MAX + 1);
                if (carry == 0)
                {
                    break;
                }
            }
            if (carry == 1)
            {
                make_part(carry);
            }
        }
        else
        {
            negative = false;
            operator--();
            negative = true;
        }
        return cp;
    }

    bint operator-(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        bint sub = bint(0);

        int carry = 0;

        if (!negative && !m.negative)
        {
            bool large = operator>=(m);
            if (large)
            {
                for (int i = 0; i < max(size_n, size_m); i++)
                {
                    long long int part_sub = get_part(i) - m.get_part(i) - carry;
                    carry = 0;
                    if (i == 0)
                    {
                        if (part_sub < 0)
                        {
                            sub.modify_part(i, PART_MAX + 1 - part_sub);
                            carry = 1;
                        }
                        else
                        {
                            sub.modify_part(i, part_sub);
                        }
                    }
                    else
                    {
                        if (part_sub < 0)
                        {
                            sub.make_part(PART_MAX + 1 - part_sub);
                            carry = 1;
                        }
                        else
                        {
                            sub.make_part(part_sub);
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < max(size_n, size_m); i++)
                {
                    long long int part_sub = m.get_part(i) - get_part(i) - carry;
                    if (i == 0)
                    {
                        if (part_sub < 0)
                        {
                            sub.modify_part(i, PART_MAX + 1 - part_sub);
                            carry = 1;
                        }
                        else
                        {
                            sub.modify_part(i, part_sub);
                        }
                    }
                    else
                    {
                        if (part_sub < 0)
                        {
                            sub.make_part(PART_MAX + 1 - part_sub);
                            carry = 1;
                        }
                        else
                        {
                            sub.make_part(part_sub);
                        }
                    }
                }
                sub.negative = !sub.negative;
            }
        }
        else if (negative && m.negative)
        {
            negative = !negative;
            m.negative = !m.negative;

            sub = operator-(m);
            sub.negative = !sub.negative;

            negative = !negative;
            m.negative = !m.negative;
        }
        else if (!negative && m.negative)
        {
            m.negative = false;

            sub = operator+(m);

            m.negative = true;
        }
        else if (negative && !m.negative)
        {
            negative = false;

            sub = operator+(m);
            sub.negative = true;

            negative = true;
        }
        return sub;
    }

    bint operator-(long long int m)
    {
        return operator-(bint(m));
    }

    bint operator-(string str_m)
    {
        return operator-(bint(str_m));
    }

    bint operator--()
    {
        int size_n = get_size();
        long long int part;
        int carry = 1;

        if (!negative)
        {
            for (int i = 0; i < size_n; i++)
            {
                part = (long long int)get_part(i);
                --part;
                if (part >= 0)
                {
                    modify_part(i, part);
                    break;
                }
                else
                {
                    modify_part(i, PART_MAX + 1 + part);
                }
            }
        }
        else
        {
            negative = false;
            operator++();
            negative = true;
        }
        return copy();
    }

    bint operator--(int)
    {
        bint cp = copy();
        int size_n = get_size();
        long long int part;
        int carry = 1;

        if (!negative)
        {
            for (int i = 0; i < size_n; i++)
            {
                part = (long long int)get_part(i);
                --part;
                if (part >= 0)
                {
                    modify_part(i, part);
                    break;
                }
                else
                {
                    modify_part(i, PART_MAX + 1 + part);
                }
            }
        }
        else
        {
            negative = false;
            operator++();
            negative = true;
        }
        return cp;
    }

    bint operator*(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        bint prod = bint(0);

        if (m == 0 || operator==(bint(0)))
        {
            return bint(0);
        }

        bint carry = bint(0);

        if ((!negative && !m.negative) || (negative && m.negative))
        {
            for (int p = 0; p < size_m + size_n; p++)
            {
                long long int part_prod = (long long int)carry.get_part(0);
                if (carry.lsp->next_part != NULL)
                {
                    carry.lsp = carry.lsp->next_part;
                }
                else
                {
                    carry.lsp->num = 0;
                }
                carry.lsp->prev_part = NULL;
                for (int i = 0; i < size_m; i++)
                {
                    for (int j = 0; j < size_n; j++)
                    {
                        if (i + j == p)
                        {
                            part_prod += (long long int)get_part(i) * m.get_part(j);
                            carry = carry + part_prod / (PART_MAX + 1);
                            part_prod = part_prod % (PART_MAX + 1);
                        }
                    }
                }
                if (p == 0)
                {
                    prod.modify_part(p, part_prod);
                }
                else
                {
                    prod.make_part(part_prod);
                }
            }
        }
        else if ((negative && !m.negative) || (!negative && m.negative))
        {
            negative = !negative;

            prod = operator*(m);
            prod.negative = !negative;

            negative = !negative;
        }

        while (prod.msp->num == 0 && prod.get_size() > 0)
        {
            prod.msp = prod.msp->prev_part;
            prod.msp->next_part = NULL;
        }

        return prod;
    }

    bint operator*(long long int m)
    {
        return operator*(bint(m));
    }

    bint operator*(string str_m)
    {
        return operator*(bint(str_m));
    }

    bint operator/(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        if (m == 0)
        {
            return NULL;
        }

        if (operator<(m))
        {
            return bint(0);
        }
        bint div = bint(0);

        bint rem = bint(0);
        for (int k = 0; k < size_n; k += size_m)
        {
            for (int i = 0; i < size_m; i++)
            {
                rem = rem * (PART_MAX + 1);

                rem = rem + get_part(size_n - i - k - 1);
            }
            int p = 1;
            while (rem >= m * p)
            {
                p++;
            }
            p--;
            rem = rem - m * p;
            div = div * 10 + p;
        }
        return div;
    }

    bint operator/(long long int m)
    {
        return operator/(bint(m));
    }

    bint operator/(string str_m)
    {
        return operator/(bint(str_m));
    }

    bint operator%(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        if (m == 0)
        {
            return NULL;
        }

        if (operator<(m))
        {
            return bint(0);
        }
        bint div = bint(0);

        bint rem = bint(0);
        for (int k = 0; k < size_n; k += size_m)
        {
            for (int i = 0; i < size_m; i++)
            {
                rem = rem * (PART_MAX + 1);

                rem = rem + get_part(size_n - i - k - 1);
            }
            int p = 1;
            while (rem >= m * p)
            {
                p++;
            }
            p--;
            rem = rem - m * p;
            div = div * 10 + p;
        }
        return rem;
    }

    bint operator%(long long int m)
    {
        return operator%(bint(m));
    }

    bint operator%(string str_m)
    {
        return operator%(bint(str_m));
    }

    bool operator==(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        if ((!negative && m.negative) || (negative && !m.negative))
        {
            return false;
        }

        else
        {
            if (size_m != size_n)
            {
                return false;
            }
            else
            {
                for (int i = 0; i < size_n; i++)
                {
                    if (get_part(i) != m.get_part(i))
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }

    bool operator==(long long int m)
    {
        return operator==(bint(m));
    }

    bool operator==(string str_m)
    {
        return operator==(bint(str_m));
    }

    bool operator!=(bint m)
    {
        return !operator==(m);
    }

    bool operator!=(long long int m)
    {
        return operator!=(bint(m));
    }

    bool operator!=(string str_m)
    {
        return operator!=(bint(str_m));
    }

    bool operator<(bint m)
    {
        int size_n = get_size();
        int size_m = m.get_size();

        if (negative && !m.negative)
        {
            return true;
        }
        else if (!negative && m.negative)
        {
            return false;
        }
        else if (!negative && !m.negative)
        {
            if (size_n > size_m)
            {
                return false;
            }
            else if (size_n < size_m)
            {
                return true;
            }
            else
            {
                for (int i = 0; i < size_n; i++)
                {
                    if (get_part(i) > m.get_part(i))
                    {
                        return false;
                    }
                    else if (get_part(i) < m.get_part(i))
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        else if (negative && m.negative)
        {
            negative = false;
            m.negative = false;

            bool small = operator<(m);

            negative = true;
            m.negative = true;

            return !small;
        }
    }

    bool operator<(long long int m)
    {
        return operator<(bint(m));
    }

    bool operator<(string str_m)
    {
        return operator<(bint(str_m));
    }

    bool operator<=(bint m)
    {
        return operator<(m) || operator==(m);
    }

    bool operator<=(long long int m)
    {
        return operator<=(bint(m));
    }

    bool operator<=(string str_m)
    {
        return operator<=(bint(str_m));
    }

    bool operator>=(bint m)
    {
        return !operator<(m);
    }

    bool operator>=(long long int m)
    {
        return operator>=(bint(m));
    }

    bool operator>=(string str_m)
    {
        return operator>=(bint(str_m));
    }

    bool operator>(bint m)
    {
        return !operator<=(m);
    }

    bool operator>(long long int m)
    {
        return operator>(bint(m));
    }

    bool operator>(string str_m)
    {
        return operator>(bint(str_m));
    }
};