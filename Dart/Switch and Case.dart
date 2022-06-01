import 'dart:io';

void main () {
    stdout.write('Masukkan Angka pertama : ');
    var firstNumber = num.parse(stdin.readLineSync().toString());
    stdout.write('Masukkan Operator [ + | - | * | / ] : ');
    var operator = stdin.readLineSync();
    stdout.write('Masukkan  Angka Kedua : ');
    var secondNumber = num.parse(stdin.readLineSync().toString());

    switch (operator) {
        case '+':
            print(
                '$firstNumber $operator $secondNumber = ${firstNumber + secondNumber }');
            break;
        case '-':
            print(
                '$firstNumber $operator $secondNumber = ${firstNumber - secondNumber }');
            break;
        case '*':
            print(
                '$firstNumber $operator $secondNumber = ${firstNumber * secondNumber}');
            break;
        case '/':
            print(
                '$firstNumber $operator $secondNumber = ${firstNumber / secondNumber}');
            break;
            default:
            print('Operator Tidak Ditemukan');           
    }
}