#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string ShiftHight(string A, int b) {
    for (int i = 0; i < b; i++) {
        A = A + "0";
    }
    return A;
}

string ShiftLow(string A, int b) {
    for (int i = 0; i < b; i++) {
        A = "0" + A;
    }
    return A;
}

string Convert(string A) {
    string B = "";
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '0') {
            B = B + "0000";
        }
        else if (A[i] == '1') {
            B = B + "0001";
        }
        else if (A[i] == '2') {
            B = B + "0010";
        }
        else if (A[i] == '3') {
            B = B + "0011";
        }
        else if (A[i] == '4') {
            B = B + "0100";
        }
        else if (A[i] == '5') {
            B = B + "0101";
        }
        else if (A[i] == '6') {
            B = B + "0110";
        }
        else if (A[i] == '7') {
            B = B + "0111";
        }
        else if (A[i] == '8') {
            B = B + "1000";
        }
        else if (A[i] == '9') {
            B = B + "1001";
        }
        else if (A[i] == 'A') {
            B = B + "1010";
        }
        else if (A[i] == 'B') {
            B = B + "1011";
        }
        else if (A[i] == 'C') {
            B = B + "1100";
        }
        else if (A[i] == 'D') {
            B = B + "1101";
        }
        else if (A[i] == 'E') {
            B = B + "1110";
        }
        else if (A[i] == 'F') {
            B = B + "1111";
        }
    }
    return B;
}

string ReverseConvert(string A) {
    string B = "";
    while (A.size() % 4 != 0) {
        A = "0" + A;
    }
    for (int i = 0; i < A.size(); i = i + 4) {
        if (A[i] == '0' && A[i + 1] == '0' && A[i + 2] == '0' && A[i + 3] == '0') {
            B = B + "0";
        }
        else  if (A[i] == '0' && A[i + 1] == '0' && A[i + 2] == '0' && A[i + 3] == '1') {
            B = B + "1";
        }
        else  if (A[i] == '0' && A[i + 1] == '0' && A[i + 2] == '1' && A[i + 3] == '0') {
            B = B + "2";
        }
        else  if (A[i] == '0' && A[i + 1] == '0' && A[i + 2] == '1' && A[i + 3] == '1') {
            B = B + "3";
        }
        else  if (A[i] == '0' && A[i + 1] == '1' && A[i + 2] == '0' && A[i + 3] == '0') {
            B = B + "4";
        }
        else  if (A[i] == '0' && A[i + 1] == '1' && A[i + 2] == '0' && A[i + 3] == '1') {
            B = B + "5";
        }
        else  if (A[i] == '0' && A[i + 1] == '1' && A[i + 2] == '1' && A[i + 3] == '0') {
            B = B + "6";
        }
        else  if (A[i] == '0' && A[i + 1] == '1' && A[i + 2] == '1' && A[i + 3] == '1') {
            B = B + "7";
        }
        else  if (A[i] == '1' && A[i + 1] == '0' && A[i + 2] == '0' && A[i + 3] == '0') {
            B = B + "8";
        }
        else  if (A[i] == '1' && A[i + 1] == '0' && A[i + 2] == '0' && A[i + 3] == '1') {
            B = B + "9";
        }
        else  if (A[i] == '1' && A[i + 1] == '0' && A[i + 2] == '1' && A[i + 3] == '0') {
            B = B + "A";
        }
        else  if (A[i] == '1' && A[i + 1] == '0' && A[i + 2] == '1' && A[i + 3] == '1') {
            B = B + "B";
        }
        else  if (A[i] == '1' && A[i + 1] == '1' && A[i + 2] == '0' && A[i + 3] == '0') {
            B = B + "C";
        }
        else  if (A[i] == '1' && A[i + 1] == '1' && A[i + 2] == '0' && A[i + 3] == '1') {
            B = B + "D";
        }
        else  if (A[i] == '1' && A[i + 1] == '1' && A[i + 2] == '1' && A[i + 3] == '0') {
            B = B + "E";
        }
        else  if (A[i] == '1' && A[i + 1] == '1' && A[i + 2] == '1' && A[i + 3] == '1') {
            B = B + "F";
        }
    }
    return B;
}

string Plus(string A, string B) {
    if (A.size() < B.size()) {
        A = ShiftLow(A, B.size() - A.size());
    }
    else if (A.size() > B.size()) {
        B = ShiftLow(B, A.size() - B.size());
    }
    string C = "";
    int carry = 0;
    int temp;
    for (int i = A.size() - 1; i >= 0; i--) {
        temp = int(A[i])-'0' + int(B[i])-'0' + carry;
        C = to_string(temp % 2) + C;
        carry = temp / 2;
    }
    if (carry == 1) {
        C = to_string(carry) + C;
    }
    return C;
}

string Minus(string A, string B) {
    if (A.size() < B.size()) {
        A = ShiftLow(A, B.size() - A.size());
    }
    else if (A.size() > B.size()) {
        B = ShiftLow(B, A.size() - B.size());
    }
    string C = "";
    int borrow = 0;
    int temp;
    for (int i = A.size() - 1; i >= 0; i--) {
        temp = (int(A[i]) - '0') - (int(B[i])- '0') - borrow;
        if (temp >= 0) {
            C = to_string(temp) + C;
            borrow = 0;
        }
        else {
            C =to_string(2+temp) + C;
            borrow = 1;
        }
    }
    return C ;
}

// 0 если А=B, 1 A>B, -1 B>A
int Compare(string A, string B) {
    if (A.size() < B.size()) {
        A = ShiftLow(A, B.size() - A.size());
    }
    else if (A.size() > B.size()) {
        B = ShiftLow(B, A.size() - B.size());
    }
    int i = 0;
    while (A[i]==B[i]) {
        if (i == A.size()-1) {
            return 0;
        }
        i ++;
    }
    if (A[i] == '1') {
        return 1;
    }
    else {
        return -1;
    }
}

string Multiplication(string A, string B) {
    if (A.size() < B.size()) {
        A = ShiftLow(A, B.size() - A.size());
    }
    else if (A.size() > B.size()) {
        B = ShiftLow(B, A.size() - B.size());
    }
    string C = "0";
    string temp;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (B[i] == '1') {
            temp = A;
        }
        else {
            temp = "0";
        }
        temp = ShiftHight(temp, A.size() - i-1);
        C = Plus(C,temp);
    }
    return C;
}

string Degree2(string A) {
    string C = "";
    C = Multiplication(A, A);
    return C;
}

string DegreeN(string A, string N) {
    string C = "1";
    for (int i = 0; i < N.size() ; i++) {
        if (N[i] == '1') {
            C = Multiplication(C, A);
        }
        if (i != N.size() - 1) {
            C = Degree2(C);
        }
    }
    return C;
}

string Delet0(string A) {
    string C = "";
    int i=0;
    while (A[i] == '0'){
        i++;
        if (i == A.size()) {
            return "0";
        }
    }
    for (int b = i; b < A.size(); b++) {
        C = C + A[b];
    }
    return C;
}

string Division(string A, string B) {
    string C = "";
    string Q = "";
    int t = 0;
    A = Delet0(A);
    Q = ShiftLow(Q, A.size());
    B = Delet0(B);
    int k = B.size();
    while (Compare(A,B)!=-1) {
        A = Delet0(A);
        t = A.size();
        C = ShiftHight(B, t - k);
        if (Compare(A,C)==-1) {
            t--;
            C = ShiftHight(B, t - k);
        }
        A = Minus(A, C);
        Q[Q.size()-1-t+k] = '1';
    }
    return Q;
}

string GSD(string A, string B) {
    string D = "1";
    string temp = "";
    while (A[A.size() - 1] ==0 && B[B.size() - 1]==0) {
        A = A.erase(A.size() - 1, 1);
        B = B.erase(B.size() - 1, 1);
        D = ShiftHight(D, 1);
    }
    while (A[A.size() - 1] == 0) {
        A = A.erase(A.size() - 1, 1);
    }
    B = Delet0(B);
    while (B != "0") {
        while (B[B.size() - 1] == '0') {
            B = B.erase(B.size()-1,1);
        }
        temp = A;
        if (Compare(A, B) == 1) {
            A = B;
            B = Minus(temp, B);
        }
        else {
            B = Minus(B, A);
        }
        B = Delet0(B);
    }
        D = Multiplication(D, A);
        return D;
}

string LCM(string A, string B, string C) {
    A = Multiplication(A, B);
    A = Division(A, C);
    return A;
}

string DeletLastDidgit(string A, int B) {
    if (A.size() <= B) {
        return "0";
    }
    else {
        A = A.erase(A.size()-B,B);
    }
    return A;
}

string Count(string Z) {
    Z = Delet0(Z);
    int x = Z.size();
    string M = ShiftHight("1",2*x);
    M = Division(M, Z);
    return M;
}

string Mod(string A, string N, string M) {
    N = Delet0(N);
    string Q = DeletLastDidgit(A, N.size()-1);
    Q = Multiplication(Q, M);
    Q = DeletLastDidgit(Q, N.size() + 1);
    Q = Multiplication(Q, N);
    A = Minus(A, Q);
    while (Compare(A,N) != -1) {
        A = Minus(A, N);
    }
    return A;
}

string PlusMod(string A, string B, string Z, string CZ) {
    A = Plus(A, B);
    A = Mod(A, Z, CZ);
    return A;
}

string MinusMod(string A, string B, string Z, string CZ) {
    A = Minus(A, B);
    A = Mod(A, Z, CZ);
    return A;
}

string MultiplicationMod(string A, string B, string Z, string CZ) {
    A = Multiplication(A, B);
    A = Mod(A, Z, CZ);
    return A;
}

string Degree2Mod(string A, string Z, string CZ) {
    A = Degree2(A);
    A = Mod(A, Z, CZ);
    return A;
}

string ModDegree(string A, string B, string Z, string CZ) {
    string N = "1";
    for(int i =B.size()-1; i>=0; i--){
        if (B[i] == '1') {
            N = Multiplication(N, A);
            N = Mod(N, Z, CZ);
        }
        A = Degree2(A);
        A = Mod(A, Z, CZ);
    }
    return A;
}

int main()
{
    string A = "D4D2110984907B5625309D956521BAB4157B8B1ECE04043249A3D379AC112E5B9AF44E721E148D88A942744CF56A06B92D28A0DB950FE4CED2B41A0BD38BCE7D0BE1055CF5DE38F2A588C2C9A79A75011058C320A7B661C6CE1C36C7D870758307E5D2CF07D9B6E8D529779B6B2910DD17B6766A7EFEE215A98CAC300F2827DB";
    string X = Convert(A);
    string B = "3A7EF2554E8940FA9B93B2A5E822CC7BB262F4A14159E4318CAE3ABF5AEB1022EC6D01DEFAB48B528868679D649B445A753684C13F6C3ADBAB059D635A2882090FC166EA9F0AAACD16A062149E4A0952F7FAAB14A0E9D3CB0BE9200DBD3B0342496421826919148E617AF1DB66978B1FCD28F8408506B79979CCBCC7F7E5FDE7";
    string Y = Convert(B);
    string N = "269D7722EA018F2AC35C5A3517AA06EAA1949059AE8240428BBFD0A8BE6E2EBF91223991F80D7413D6B2EB213E7122710EDEC617460FA0191F3901604619972018EBEF22D81AED9C56424014CADCC2CCDEE67D36A54BFC500230CA6693ABA057B374746622341ED6D52FE5A79E6860F54F197791B3FEF49FD534CB2C675B6BDB";
    string T = Convert(N);
    string Z = T;//модульs
    string CZ = Count(T);
    
    //cout <<"+ "<< ReverseConvert( PlusMod(X,Y, Z, CZ)) << endl;
    cout << "- " << ReverseConvert( MinusMod(X,Y,Z,CZ)) << endl;
    //cout<<"^ "<<ReverseConvert( ModDegree(X, Y, Z, CZ)) << endl;

    string gsd = GSD(X, Y);
    
   // cout <<"gsd"<<ReverseConvert( gsd) << endl;
    //cout <<"lcm"<<ReverseConvert( LCM(X, Y, gsd) )<< endl;
    
    /*    cout << "Test one" << endl;
    string W = PlusMod(X, Y, Z, CZ);
    cout << Compare(MultiplicationMod(W, T,Z, CZ), MultiplicationMod(T, W,Z ,CZ)) << endl;
    string E = PlusMod(MultiplicationMod(X, T,Z, CZ), MultiplicationMod(Y, T, Z, CZ),Z, CZ);
    cout << Compare(MultiplicationMod(W, T,Z, CZ), E) << endl;

    cout << "Test two" << endl;
    W = MultiplicationMod(T, X,Z,CZ);
    E = X;
    for (int i = 0; i < 99; i++) {
        E = PlusMod(E, X,Z, CZ);
    }
    cout << Compare(W, E) << endl;
    */
    
    /*
    cout << "Test one" << endl;
    string W = Plus(X,Y);
    cout << Compare(Multiplication(W,T),Multiplication(T,W)) << endl;
    string E = Plus(Multiplication(X,T),Multiplication(Y,T));
    cout << Compare(Multiplication(W, T), E) << endl;

    cout << "Test two" << endl;
    W = Multiplication(T, X);
    E = X;
    for (int i = 0; i < 99; i++) {
        E = Plus(E,X);
    }
    cout << Compare(W,E) << endl;
    */

    /*cout <<"A&B"  << Compare(X, Y) << endl;
    cout <<"+ " << ReverseConvert(Plus(X, Y)) << endl;
    if (Compare(X,Y) == -1) {
        cout << "Negative number" << endl;
    }
    else {
        cout <<"- "<<ReverseConvert( Minus(X, Y) )<< endl;
    }*/
    //cout <<"* "<<ReverseConvert( Multiplication(X, Y) )<< endl;
    //cout <<"^2 "<<ReverseConvert( Degree2(X) )<< endl;
    //cout <<"^B "<<ReverseConvert( DegreeN(X, Y)) << endl;
    
    // string F = Multiplication(X,Y);
    //cout <<"/ "<<ReverseConvert( Division(F, Y) )<< endl;

    
    return 0;
}
