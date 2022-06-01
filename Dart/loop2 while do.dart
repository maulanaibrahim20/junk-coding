void tampilkan(text) {
  print(text);
}

dynamic proses(nilai, operator) {
  switch (operator) {
    case '+':
      return nilai + nilai;
      break;
    case '-':
      return nilai - nilai;
      break;
    case '*':
      return nilai * nilai;
      break;
    case '/':
      return nilai / nilai;
      break;
    default:
      return 0;
      break;
  }
}

void main() {
  var operator = ['+', '-', '*', '/'];
  var data = [5, 4, 3, 2, 1];
  for (var i = 0; i < operator.length; i++) {
    tampilkan(proses(data[i], operator[i]));
  }
}