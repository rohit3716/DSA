//https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio
bool isValidParenthesis(string expression)
{
    stack<char> s ;
    for( int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        //if opening baracket, push stack
        // if closing bracket , check stack top and pop

        if( ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else {
            //for closing bracket
            if (!s.empty()) {
              char top = s.top();
              if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                      s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty())
    return true;
    else
    return false;
}