void main() {
  var numberSet = {1, 4, 6};
  // ignore: prefer_collection_literals
  var anotherSet = Set<int>.from([1, 4, 6, 4, 1]);

  print(numberSet);
  print(anotherSet);
}