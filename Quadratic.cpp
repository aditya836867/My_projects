#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//   Negative_Sign_Check Determination
string Negative_Sign_Check(int x) {
  if (x >= 0) {
    return "+";
  } else {
    return "";
  }
}
// Return Negative and Positive
int Return_sign(string x) {
  if (x == "+") {
    return 1;
  } else {
    return -1;
  }
}
//   Sign Check
string Sign_Check(int x) {
  if (x >= 0) {
    return "+";
  } else {
    return "-";
  }
}
//   Positive Conversion
int convert_positive(int x) {
  if (x < 0) {
    return x * -1;
  } else {
    return x;
  }
}
//   HCF of 2 Numbers
int hcf_2(int n1, int n2) {
  int hcf;
  hcf = 1;
  for (int i = 1; i <= min(n1, n2) + 1; i++) {
    if (n1 % i == 0 && n2 % i == 0) {
      hcf = i;
    }
  }
  return hcf;
}
//   Lowest Number Among 3 Numbers
int lowest_num_3(int a, int b, int c) {
  int minnumber;
  if (a > b) {
    minnumber = b;
  } else {
    minnumber = a;
  }
  if (minnumber > c) {
    minnumber = c;
  }
  return minnumber;
}
//   HCF of 3 Numbers
int hcf_3(int n1, int n2, int n3) {
  int hcf, div;
  div = lowest_num_3(n1, n2, n3);
  for (int i = 1; i <= div + 1; i++) {
    if (n1 % i == 0 && n2 % i == 0 && n3 % i == 0) {
      hcf = i;
    }
  }
  return hcf;
}
//   Prime Factors
vector<int> prime_factors(int n) {
  vector<int> factors;
  while (n % 2 == 0) {
    factors.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      factors.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    factors.push_back(n);
  }
  return factors;
}
//   Result Decoration
void result(float a, float b) {
  if (a == int(a) && b == int(b)) {
    int div, x, y;
    x = convert_positive(a);
    y = convert_positive(b);
    div = hcf_2(x, y);
    a = a / div;
    b = b / div;
    if (b == 1) {
      cout << "  "
           << "x = " << a << endl;
    } else if (b == (-1)) {
      cout << "  "
           << "x = " << a / (-1) << endl;
    } else if (a == 0) {
      cout << "  "
           << "x = " << 0 << endl;
    } else {
      cout << "  "
           << "x = " << a << "/" << b << endl;
    }
  } else {
    cout << "  "
         << "x = " << a / b;
  }
}
//   Quadratic Equation
void determinant_method(int a, int b, int c) {
  float D, num1, num2, num4, num5;
  string r1, r2;
  cout << endl << "Quadratic Equation:" << endl;
  cout << a << "x²" << Negative_Sign_Check(b) << b << "x"
       << Negative_Sign_Check(c) << c << '=' << 0 << endl;
  if (a < 0) {
    cout << -1 * a << "x²" << Negative_Sign_Check(-1 * b) << -1 * b << "x"
         << Negative_Sign_Check(-1 * c) << -1 * c << '=' << 0 << endl
         << endl;
    a = -1 * a;
    b = -1 * b;
    c = -1 * c;
  } else {
    cout << endl;
  }
  cout << "Finding Discriminant: " << endl;
  cout << "D = b² - 4ac" << endl;
  cout << "D = "
       << "(" + to_string(b) + ")" + "*" + "(" + to_string(b) + ")"
       << " - 4*"
       << "(" << a << ")"
       << "*"
       << "(" << c << ")" << endl;
  cout << "D = " << b * b << " -"
       << "(" << 4 * a * c << ")" << endl;
  cout << "D = " << b * b - 4 * a * c << endl << endl;
  D = b * b - 4 * a * c;
  if (D < 0) {
    cout << "The Discriminant is Negative So No Real Solutions are Possible"
         << endl;
  } else {
    if (int(sqrt(D)) == sqrt(D)) {
      cout << "Finding Roots: " << endl;
      cout << "x = (-b ± √D) / 2a" << endl;
      cout << "x = "
           << "("
           << "-(" << b << ") ± √" << D << ")"
           << " / "
           << "("
           << "2*"
           << "(" << a << ")"
           << ")" << endl;
      cout << "x = "
           << "(" << (-1) * b << " ± " << sqrt(D) << ")"
           << " / "
           << "(" << 2 * a << ")" << endl
           << endl;

      cout << "  "
           << "First Root:" << endl;
      cout << "  "
           << "x = "
           << "(" << (-1) * b << " + " << sqrt(D) << ")"
           << " / "
           << "(" << 2 * a << ")" << endl;
      cout << "  "
           << "x = "
           << "(" << (-1) * b + sqrt(D) << ")"
           << " / "
           << "(" << 2 * a << ")" << endl;
      num1 = (-1) * b + sqrt(D);
      num2 = 2 * a;
      result(num1, num2);
      cout << endl;

      cout << "  "
           << "Second Root:" << endl;
      cout << "  "
           << "x = "
           << "(" << (-1) * b << " - " << sqrt(D) << ")"
           << " / "
           << "(" << 2 * a << ")" << endl;
      cout << "  "
           << "x = "
           << "(" << (-1) * b - sqrt(D) << ")"
           << " / "
           << "(" << 2 * a << ")" << endl;
      num4 = (-1) * b - sqrt(D);
      num5 = 2 * a;
      result(num4, num5);
      cout << endl << endl;
    } else {
      vector<int> factor = prime_factors(int(D));
      cout << "Finding Roots: " << endl;
      cout << "x = (-b ± √D) / 2a" << endl;
      cout << "x = "
           << "("
           << "-(" << b << ") ± √" << D << ")"
           << " / "
           << "("
           << "2*"
           << "(" << a << ")"
           << ")" << endl;
      int D_rootin, D_rootout, count, last_factor;
      D_rootin = 1;
      D_rootout = 1;
      count = 0;
      last_factor = 0;

      for (int i = 0; i < factor.size(); i++) {
        if (factor[i] == last_factor) {
          count += 1;
          if (count == 2) {
            D_rootout *= factor[i];
            count = 0;
          }
        } else {
          if (count == 1) {
            D_rootin *= last_factor;
          }
          last_factor = factor[i];
          count = 1;
        }
      }

      // Check if there's any remaining factor inside the root
      if (count == 1) {
        D_rootin *= last_factor;
      }

      cout << "x = "
           << "(" << -1 * b << " ± " << D_rootout << "√" << D_rootin << ")"
           << " / "
           << "(" << 2 * a << ")" << endl;
      int num;
      num = hcf_3(convert_positive(b), D_rootout, convert_positive(2 * a));
      cout << "x = " << num << "*"
           << "(" << -1 * b / num << " ± " << D_rootout / num << "√" << D_rootin
           << ")"
           << " / " << num << "*"
           << "(" << 2 * a / num << ")" << endl;
      cout << "x = "
           << "(" << -1 * b / num << " ± " << D_rootout / num << "√" << D_rootin
           << ")"
           << " / "
           << "(" << 2 * a / num << ")" << endl
           << endl;

      cout << "  "
           << "First Root:" << endl;
      cout << "  "
           << "x = "
           << "(" << -1 * b / num << " + " << D_rootout / num << "√" << D_rootin
           << ")"
           << " / "
           << "(" << 2 * a / num << ")" << endl;
      if (2 * a / num < 0) {
        cout << "  "
             << "x = "
             << "(" << b / num << " - " << D_rootout / num << "√" << D_rootin
             << ")"
             << " / "
             << "(" << -1 * 2 * a / num << ")" << endl;
      }
      float x, y, z;
      x = (-1 * b) + sqrt(D);
      y = 2 * a;
      z = x / y;
      cout << "  "
           << "---Experimental Value---" << endl
           << "  x = " << z << endl
           << endl;

      cout << "  "
           << "Second Root:" << endl;
      cout << "  "
           << "x = "
           << "(" << -1 * b / num << " - " << D_rootout / num << "√" << D_rootin
           << ")"
           << " / "
           << "(" << 2 * a / num << ")" << endl;
      if (2 * a / num < 0) {
        cout << "  "
             << "x = "
             << "(" << b / num << " + " << D_rootout / num << "√" << D_rootin
             << ")"
             << " / "
             << "(" << -1 * 2 * a / num << ")" << endl;
      }
      x = (-1 * b) - sqrt(D);
      y = 2 * a;
      z = x / y;
      cout << "  "
           << "---Experimental Value---" << endl
           << "  x = " << z << endl
           << endl;
    }
  }
}
//   Split Check;
int split_check(int a, int b, int c) {
  int count;
  int ac = a * c;
  count = 0;
  for (int i = -abs(ac); i <= abs(ac); ++i) {
    if (i != 0 && ac % i == 0) {
      int j = ac / i;
      if (i + j == b) {
        count = 1;
      }
    }
  }
  if (count == 1) {
    return 1;
  } else {
    return 0;
  }
}
//   Split Method
void split_middle(int a, int b, int c) {
  cout << endl << "Quadratic Equation:" << endl;
  cout << a << "x²" << Negative_Sign_Check(b) << b << "x"
       << Negative_Sign_Check(c) << c << '=' << 0 << endl;
  if (a < 0) {
    cout << -1 * a << "x²" << Negative_Sign_Check(-1 * b) << -1 * b << "x"
         << Negative_Sign_Check(-1 * c) << -1 * c << '=' << 0 << endl
         << endl;
    a = -1 * a;
    b = -1 * b;
    c = -1 * c;
  } else {
    cout << endl;
  }
  cout << "Splitting The Middle Term: " << endl;
  int split1, split2;
  int ac = a * c;
  for (int i = -abs(ac); i <= abs(ac); ++i) {
    if (i != 0 && ac % i == 0) {
      int j = ac / i;
      if (i + j == b) {
        split1 = i;
        split2 = j;
      }
    }
  }
  cout << a << "x²" << Negative_Sign_Check(split1) << split1 << "x"
       << Negative_Sign_Check(split2) << split2 << "x" << Negative_Sign_Check(c)
       << c << '=' << 0 << endl;
  int hcf1, hcf2;
  hcf1 = hcf_2(abs(a), abs(split1));
  hcf2 = hcf_2(abs(split2), abs(c));
  if (Negative_Sign_Check(split2) == "+") {
    cout << hcf1 << "x"
         << "(" << a / hcf1 << "x" << Negative_Sign_Check(split1)
         << split1 / hcf1 << "x"
         << ")" << Negative_Sign_Check(split2) << hcf2 << "(" << split2 / hcf2
         << "x" << Negative_Sign_Check(c) << c / hcf2 << ")" << '=' << 0
         << endl;
  } else {
    cout << hcf1 << "x"
         << "(" << a / hcf1 << "x" << Negative_Sign_Check(split1)
         << split1 / hcf1 << ")" << Sign_Check(split2) << hcf2 << "("
         << abs(split2 / hcf2) << "x" << Negative_Sign_Check(-1 * c)
         << -1 * c / hcf2 << ")" << '=' << 0 << endl;
  }
  cout << "(" << a / hcf1 << "x" << Negative_Sign_Check(split1) << split1 / hcf1
       << ")"
       << "(" << hcf1 << "x" << Sign_Check(split2) << hcf2 << ")"
       << "=" << 0 << endl
       << endl;

  cout << "First Root: " << endl;
  cout << a / hcf1 << "x" << Negative_Sign_Check(split1) << split1 / hcf1 << "="
       << 0 << endl;
  cout << a / hcf1 << "x"
       << "=" << 0 << Negative_Sign_Check(-1 * split1) << -1 * split1 / hcf1
       << endl;
  cout << a / hcf1 << "x"
       << "=" << -1 * split1 / hcf1 << endl;
  cout << "x"
       << "="
       << "(" << -1 * split1 / hcf1 << ")"
       << "/(" << a / hcf1 << ")" << endl;
  int hcf3;
  int num1, num2;
  hcf3 = hcf_2(abs(-1 * split1 / hcf1), abs(a / hcf2));
  num1 = (a / hcf1) / hcf3;
  num2 = -1 * split1 / hcf1 / hcf3;
  if (num1 == 1) {
    cout << "x"
         << "=" << num2 << endl
         << endl;
  } else {
    cout << "x"
         << "="
         << "(" << num2 << ")/(" << num1 << ")" << endl
         << endl;
  }

  cout << "Second Root: " << endl;
  cout << hcf1 << "x" << Sign_Check(split2) << hcf2 << "=" << 0 << endl;
  cout << hcf1 << "x"
       << "=" << 0 << Sign_Check(-1 * split2) << hcf2 << endl;
  int sign = Return_sign(Sign_Check(-1 * split2));
  cout << hcf1 << "x"
       << "=" << sign * hcf2 << endl;
  cout << "x"
       << "="
       << "(" << sign * hcf2 << ")/(" << hcf1 << ")" << endl;
  int hcf4;
  hcf4 = hcf_2(abs(sign * hcf2), abs(hcf1));
  num1 = sign * hcf2 / hcf4;
  num2 = hcf1 / hcf4;
  if (num2 == 1) {
    cout << "x"
         << "=" << num1 << endl
         << endl;
  } else {
    cout << "x"
         << "="
         << "(" << num1 << ")/(" << num2 << ")" << endl;
  }
}
//   Capital
string cap(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (isalpha(str[i])) {
      str[i] = toupper(str[i]);
    }
  }
  return str;
}
//   Main Function
int main() {
  string retry = "Y";
  while (retry == "Y") {
    int a, b, c;
    cout << "Standard Quadratic Equation: ax²+bx+c" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "---------Determinant Method---------\n";
    determinant_method(a, b, c);
    cout << endl;
    cout << "---------Split Method---------\n";
    int count;
    count = split_check(a, b, c);
    if (count == 1) {
      split_middle(a, b, c);
    } else {
      cout << "No Split Method Possible" << endl << endl;
    }
    string choice;
    cout << "Do You Wanna Retry? (Yes/No): ";
    cin >> choice;
    cout << endl;
    choice = cap(choice);
    if (choice == "YES") {
      retry = "Y";
    } else {
      retry = "N";
    }
  }
}
