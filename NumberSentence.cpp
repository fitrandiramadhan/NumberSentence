//file    : NumberSentence.cpp
//author  : steaKK

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

string base100[101] = {
  "nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",
  "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas",
  "dua puluh", "dua puluh satu", "dua puluh dua", "dua puluh tiga", "dua puluh empat", "dua puluh lima", "dua puluh enam", "dua puluh tujuh", "dua puluh delapan", "dua puluh sembilan",
  "tiga puluh", "tiga puluh satu", "tiga puluh dua", "tiga puluh tiga", "tiga puluh empat", "tiga puluh lima", "tiga puluh enam", "tiga puluh tujuh", "tiga puluh delapan", "tiga puluh sembilan",
  "empat puluh", "empat puluh satu", "empat puluh dua", "empat puluh tiga", "empat puluh empat", "empat puluh lima", "empat puluh enam", "empat puluh tujuh", "empat puluh delapan", "empat puluh sembilan",
  "lima puluh", "lima puluh satu", "lima puluh dua", "lima puluh tiga", "lima puluh empat", "lima puluh lima", "lima puluh enam", "lima puluh tujuh", "lima puluh delapan", "lima puluh sembilan",
  "enam puluh", "enam puluh satu", "enam puluh dua", "enam puluh tiga", "enam puluh empat", "enam puluh lima", "enam puluh enam", "enam puluh tujuh", "enam puluh delapan", "enam puluh sembilan",
  "tujuh puluh", "tujuh puluh satu", "tujuh puluh dua", "tujuh puluh tiga", "tujuh puluh empat", "tujuh puluh lima", "tujuh puluh enam", "tujuh puluh tujuh", "tujuh puluh delapan", "tujuh puluh sembilan",
  "delapan puluh", "delapan puluh satu", "delapan puluh dua", "delapan puluh tiga", "delapan puluh empat", "delapan puluh lima", "delapan puluh enam", "delapan puluh tujuh", "delapan puluh delapan", "delapan puluh sembilan",  
  "sembilan puluh", "sembilan puluh satu", "sembilan puluh dua", "sembilan puluh tiga", "sembilan puluh empat", "sembilan puluh lima", "sembilan puluh enam", "sembilan puluh tujuh", "sembilan puluh delapan", "sembilan puluh sembilan", 
  "seratus" 
};

string base1000[6] = {
  "nol", "ribu", "juta", "miliar", "triliun", "quadriliun"
};

string solve_triplets(long triplets) {
  if(triplets<101) return base100[triplets];
  else {
    if(triplets/100==1) return " " + base100[100] + " " + base100[triplets%100];
    return " " + base100[triplets/100] + " " + "ratus" + " " + base100[triplets%100];
  }
}

string solve_cubic(long numbers, int cubic) {
  cout << endl;
  cout << "iteration cubic = " << cubic << endl;
  cout << "numbers = " << numbers << endl;
  cout << "cubic = " << cubic << endl;
  cout << "1000^cubic = " << (long)pow(1000,cubic) << endl;
  cout << "1000^(cubic+1) = " << (long)pow(1000,cubic+1) << endl;
  cout << "numbers % 1000^(cubic+1) = " << (long)(numbers%((long)pow(1000,(cubic+1)))) << endl;
  cout << "numbers / 1000^(cubic+1) = " << (long)(numbers/(pow(1000,(cubic+1)))) << endl;

  if(numbers==0) {
    cout << "aloha1" << endl;
    return "";
  } 
  else if(cubic==1 && numbers/1000<2) {
    cout << "aloha2" << endl;
    return solve_cubic((long)(numbers/(pow(1000,(cubic+1)))),cubic+1) +   "seribu";
  } 
  else {
    if(numbers/((long)pow(1000,cubic))<1) {
      cout << "aloha3" << endl;
      // cout << numbers << endl;
      // cout << numbers/((long)pow(1000,cubic+1)) << endl;
      return solve_triplets(numbers);
    } 
    else {
      cout << "aloha4" << endl;
      // cout << numbers << endl;
      // cout << cubic << endl;
      // cout << (long)pow(1000,cubic+1) << endl;
      // cout << numbers%((long)pow(1000,cubic+1)) << endl;;
      return solve_cubic((long)(numbers/(pow(1000,cubic+1))),cubic+1) + " " + base1000[cubic+1] + solve_triplets((long)(numbers%((long)pow(1000,(cubic+1)))));
    } 
  }
}

string solve(long numbers) {
  if(numbers==0) return base100[0] + " rupiah";
  else return solve_cubic(numbers,0) + " rupiah";
}

int main () {
  long n = 8172937192;
  cout << n << endl;
  cout << solve(n) << endl;
}

