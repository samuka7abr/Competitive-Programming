#!/bin/bash

cd CodeForces/

read -p "Contest name: " contest_name
read -p "Number of problems: " num_problems

mkdir -p "$contest_name"

template_code='#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18;  
const double PI = acos(-1.0);

int main(){
    otim;
    
    return 0;
}'

for ((i=1; i<=num_problems; i++)); do
  dir_name=$(printf "%02d" "$i")
  letter=$(printf "\\$(printf '%03o' $((64 + i)))")

  mkdir -p "$contest_name/$dir_name"
  echo "$template_code" > "$contest_name/$dir_name/${letter}.cpp"
  mkdir -p "$contest_name/$dir_name/args"
  touch "$contest_name/$dir_name/args/input"
  touch "$contest_name/$dir_name/args/expected"
done

mkdir -p "$contest_name/questoes"

echo "Contest structure created at: codeforces/$contest_name"
