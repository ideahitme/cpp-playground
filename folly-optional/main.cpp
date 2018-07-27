#include <iostream>
#include <folly/Optional.h>
#include <folly/futures/Future.h>
#include <string>

struct User { 
	std::string name;
	folly::Optional<std::string> car;
	User(std::string name, folly::Optional<std::string> car):name(name), car(car) {};
};

folly::Future<int> subscribe(
		std::vector<std::string> names
		) { 
	std::cout << names.size() << std::endl;
	folly::Future<int> resp = folly::makeFuture(1);
	return resp;
}
int main() { 
	User u("name", folly::Optional<std::string>("mycar"));
	std::cout << u.name << " " << u.car.value() << std::endl;

	User v("name", folly::none);
	std::cout << v.name << " " << v.car.value_or("default car") << std::endl;
	return 1;

	auto resp = subscribe({});
	resp.wait();
	std::cout << resp.value() << std::endl;
}


