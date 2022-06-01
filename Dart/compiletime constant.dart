import 'dart:io';

void main () {
    final firstName = stdin.readLineSync();
    final lastName = stdin.readLineSync();
    
    print('Hello $firstName $lastName');
}