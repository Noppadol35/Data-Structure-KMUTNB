# Lab 2
Develop parenthesis matching program which can match in input
string using stack

- **Round brackets: ( )**
- **Square brackets: [ ]**
- **Curly brackets: { }**
- **Angle brackets: <> and << >> (specific case)**


### **Input** 
string (user can enter whitespace)

### **Output**
- Case 1: If they are matched, shows the number of pair following by “matched”
- Case 2: If they are not matched, shows the two-line result
    - Line 1: shows “Not matched”
    - Line 2: shows number of pairs which are matched before the parenthesis that is not
matched following by “matched”

| Input1 | Output1 |
|-|-|
|(((20+5)+61|Not matched, 1 matched|
|(20+[30 – 40<int> + 50]- a[40]{}) | 5 matched |
|>20(30{40[20]})< | Not matched, 0 matched
|<<a+<int>b+c[40-{50+60(20)}]-<int>+b>> | 6 matched |
|a+b-<<c+d<< -f ({d[30]})>> | Not matched, 4 matched