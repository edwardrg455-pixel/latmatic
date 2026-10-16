#ifndef LATMATIC_HPP
#define LATMATIC_HPP

#include <string>

namespace latmatic {}

namespace latmatic {
    class Expression; // type not for users
    template<typename Type> class Scalar;
    template<typename Type> class Set;
    template<typename Type> class Sequence;
    template<typename Type> class Series;
    template<typename Type> class Vector;
    template<typename Type> class Matrix;


    class Expression {
    private:
        std::string expr_str;
        constexpr bool is_valid_latex(const std::string &_expr) const;
        constexpr bool is_just_variable(const std::string &_expr) const;
        constexpr bool is_addition_commutative(const std::string &_expr) const;
        constexpr bool is_addition_associative(const std::string &_expr) const;
        constexpr bool is_addition_identity(const std::string &_expr) const;
        constexpr bool is_addition_inverse(const std::string &_expr) const;
        constexpr bool is_multiplication_commutative(const std::string &_expr) const;
        constexpr bool is_multiplication_associative(const std::string &_expr) const;
        constexpr bool is_multiplication_identity(const std::string &_expr) const;
        constexpr bool is_multiplication_inverse(const std::string &_expr) const;
        bool valid_latex_state;
        bool just_variable_state;
        bool addition_commutative_state;
        bool addition_associative_state;
        bool addition_identity_state;
        bool addition_inverse_state;
        bool multiplication_commutative_state;
        bool multiplication_associative_state;
        bool multiplication_identity_state;
        bool multiplication_inverse_state;
    public:
        Expression(std::string &_expr_str);
        constexpr std::string get_expr() const;
    };

    template<typename Type> class Scalar {
    private:
        Type scalar_value;
        Expression scalar_variable;
        bool scalar_value_state;
        bool scalar_var_state;
        constexpr bool is_scalar_value(const Type &_variable) const;
        constexpr bool is_scalar_var(const Expression &_variable) const;
    public:
        Scalar(Type &_variable);
    };

    template<typename Type> class Set {
    private:
        Scalar<Scalar<Type>> set;
        bool valid_set_state;
        bool set_just_value_state;
        bool set_just_var_state;
        bool set_both_state;
        constexpr bool is_valid_set(const Scalar<Scalar<Type>> &_set) const;
        constexpr bool is_set_just_value(const Scalar<Scalar<Type>> &_set) const;
        constexpr bool is_set_just_var(const Scalar<Scalar<Type>> &_set) const;
        constexpr bool is_set_both(const Scalar<Scalar<Type>> &_set) const;
    public:
        Set(Scalar<Scalar<Type>> &_set);
    };

    template<typename Type> class Sequence {
    private:
        Set<Type> sequence;
        bool valid_sequence_state;
        constexpr bool is_valid_sequence(const Scalar<Scalar<Type>> &_sequence) const;
    public:
        Sequence(Scalar<Scalar<Type>> &_sequence);
    };
    template<typename Type> class Series {
    private:
        Sequence<Type> series;
        bool valid_series_state;
        constexpr bool is_valid_series(const Scalar<Scalar<Type>> &_series) const;
    public:
        Series(Scalar<Scalar<Type>> &_series);
    };

    template<typename Type> class Vector {
    private:
        Sequence<Type> vector;
        bool valid_vector_state;
        constexpr bool is_valid_vector(const Scalar<Scalar<Type>> &_vector) const;
    public:
        Vector(Scalar<Scalar<Type>> &_vector);
    };

    template<typename Type> class Matrix {
    private:
        Vector<Vector<Type>> matrix;
        bool valid_matrix_state;
        constexpr bool is_valid_matrix(const Vector<Vector<Type>> &_matrix) const;
    public:
        Matrix(Vector<Vector<Type>> &_matrix);
    };
}

#endif
