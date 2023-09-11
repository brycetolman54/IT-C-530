#include <array>
#include <vector>
#include <iostream>

// Class representing a rectangular plane with Dirichlet boundary conditions over which waves propagate
// Called "orthotope" rather than "rectangle" since extra credit is given for generalizing to arbitrary dimension
class WaveOrthotope {
    // Types
    using size_type = size_t;
    using value_type = double;

    // Members
    const size_type m, n;              // size
    const value_type c;                // damping coefficient
    value_type t;                      // simulation time
    std::vector<value_type> disp, vel; // displacement and velocity arrays

public:
    // Constructor
    // USAGE: auto my_wave_orthotope = WaveOrthotope(20, 30, 0.1, 0);
    // SEE: https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
    WaveOrthotope(const auto m, const auto n, const auto c, const value_type t=0): m(m), n(n), c(c), t(t), disp(m*n), vel(m*n) {}

    // Return the size as a std::array
    // USAGE: const auto [rows, cols] = my_wave_orthotope.size();
    // SEE: https://codeburst.io/c-17-structural-binding-180696f7a678#63b1
    constexpr const auto size() const { return std::array{m, n}; }

    // Displacement indexing
    // USAGE: my_wave_orthotope.u(1, 2) = 1.0;
    constexpr const value_type  u(const auto i, const auto j) const { return disp[i*n+j]; }
    constexpr       value_type& u(const auto i, const auto j)       { return disp[i*n+j]; }

    // Displacement velocity indexing
    // USAGE: const auto v12 = my_wave_orthotope.v(1, 2);
    constexpr const value_type  v(const auto i, const auto j) const { return vel [i*n+j]; }
    constexpr       value_type& v(const auto i, const auto j)       { return vel [i*n+j]; }

    // Return the energy contained in this WaveOrthotope
    // USAGE: const auto E = my_wave_orthotope.energy();
    const value_type energy() const {
        value_type E{};
        // TODO: calculate total energy
        return E;
    }

    // Advance the membrane in time by dt
    // USAGE: my_wave_orthotope.step();
    const value_type step() {
        const value_type dt = 0.01;
        // TODO: update u and v by one time step
        t += dt;
        return t;
    }

    // Advance the membrane in time by steps of dt until the average interior cell energy drops below 0.001
    // USAGE: const auto sim_time = my_wave_orthotope.solve();
    const value_type solve() {
        while (energy() > (m-2)*(n-2)*0.001) {
            step();
        }
        return t;
    }
};


int main() {
    // Create WaveOrthotope
    auto m = 25, n = 50;
    auto c = 0.01;
    auto w = WaveOrthotope(25, 50, 0.01);
    // TODO: set interior cells of v to 0.1
    // Solve and print result
    std::cout << w.solve() << std::endl;
    return 0;
}