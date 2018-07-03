struct LargeDocument{};

void modify(LargeDocument & document);

void changeDocument() {
  LargeDocument const document{};
  modify(document);
}


