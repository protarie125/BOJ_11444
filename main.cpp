#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;

constexpr auto mod = ll{ 1'000'000'007 };

vvl matp(const ll& n) {
	if (1 == n) {
		return vvl{ {1,1}, {1,0} };
	}

	if (1 == n % 2) {
		const auto& q = matp(n - 1);
		auto ret = vvl(2, vl(2));
		ret[0][0] = (q[0][0] + q[0][1]) % mod;
		ret[0][1] = q[0][0];
		ret[1][0] = (q[1][0] + q[1][1]) % mod;
		ret[1][1] = q[1][0];

		return ret;
	}

	const auto& q = matp(n / 2);
	auto ret = vvl(2, vl(2));
	ret[0][0] = ((q[0][0] * q[0][0]) % mod + (q[0][1] * q[1][0]) % mod) % mod;
	ret[0][1] = ((q[0][0] * q[0][1]) % mod + (q[0][1] * q[1][1]) % mod) % mod;
	ret[1][0] = ((q[1][0] * q[0][0]) % mod + (q[1][1] * q[1][0]) % mod) % mod;
	ret[1][1] = ((q[1][0] * q[0][1]) % mod + (q[1][1] * q[1][1]) % mod) % mod;

	return ret;
}

ll solve(const ll& n) {
	if (0 == n) {
		return 0;
	}

	if (1 == n) {
		return 1;
	}

	const auto& q = matp(n);

	return q[1][0];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n;
	cin >> n;

	const auto& ans = solve(n);
	cout << ans;

	return 0;
}