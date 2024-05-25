    myStack<char>s1;
    const char* str = "(((a+b))";
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i]=='(')
        s1.push(str[i]);
        if (str[i] == ')')
        {
            if (s1.Size() == 0)
                s1.push(str[i]);
            else s1.pop();
        }
        i++;
    }

    if (s1.Size() == 0)
        cout << "paranthesis matches" << endl;
    else
        cout << "not matched" << endl;
