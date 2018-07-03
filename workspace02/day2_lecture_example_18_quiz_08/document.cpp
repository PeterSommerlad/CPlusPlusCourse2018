struct LargeDocument{};

void print(LargeDocument const & document) {}

void printAll() {
  LargeDocument document{};
  print(document);
}

int main() {
	printAll();
}
