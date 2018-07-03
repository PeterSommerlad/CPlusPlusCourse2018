
struct Address{};
struct Connection{
	Address address;
};

Connection & connect(Address address) {
	Connection connection{address};
	//..
	return connection;
}
