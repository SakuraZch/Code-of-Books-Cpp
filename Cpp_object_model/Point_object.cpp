
// 2020/4/19 //

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

// first achievement: construct directly
namespace First
{
    class Point3d
    {
        private:
            double x_;
            double y_;
            double z_;

        public:
            Point3d(double x, double y, double z):
                x_(x), y_(y), z_(z) {}
            ~Point3d() {}

            double GetX() const { return this->x_; }
            double GetY() const { return this->y_; }
            double GetZ() const { return this->z_; }
    };

    inline std::ostream& operator<<(std::ostream& os, const Point3d& pt)
    {
        os << "(" << pt.GetX() << ", " << pt.GetY() << ", " << pt.GetZ() << ")" << std::endl;
        return os;
    }
}

// second achievement: derive from a base class
namespace Second
{
    // point with one demension
    class Point1d
    {
        private:
            double x_;
        public:
            Point1d(double x):
                x_(x) {}
            ~Point1d() {}

            // use virtual function to avoid rewrite non-virtual function with same name
            virtual double GetX() const { return this->x_; }
    };

    // point with two demension
    class Point2d: public Point1d
    {
        private:
            double y_;
        public:
            Point2d(double x, double y):
                Point1d(x), y_(y) {}
            ~Point2d() {}

            virtual double GetX() const { return Point1d::GetX(); }
            virtual double GetY() const { return this->y_; }
    };

    // point with three demension
    class Point3d: public Point2d
    {
        private:
            double z_;
        public:
            Point3d(double x, double y, double z):
                Point2d(x, y), z_(z) {}
            ~Point3d() {}

            virtual double GetX() const { return Point2d::GetX(); }
            virtual double GetY() const { return Point2d::GetY(); }
            virtual double GetZ() const { return this->z_; }
    };

    inline std::ostream& operator<<(std::ostream& os, const Point3d& pt)
    {
        os << "(" << pt.GetX() << ", " << pt.GetY() << ", " << pt.GetZ() << ")" << std::endl;
        return os;
    }
}

// third achievement: use template technique which contained type and demension of point
namespace Third
{
    template <typename T, int dim>
    class PointNd
    {
        private:
            std::vector<T> coords_; // vector to store component

        public:
            PointNd(const std::vector<T>& coords):
                coords_(coords) {}
            ~PointNd() {}

            // overload operator "[]" to get element value
            T& operator[](int ind) // non-const edition
            {
                assert(0 <= ind && ind < dim);
                return this->coords_[ind];
            }
            const T& operator[](int ind) const // const edition
            {
                assert(0 <= ind && ind < dim);
                return this->coords_[ind];
            }

            // this operator "<<" must be definite and achieve inside the class
            friend std::ostream& operator<<(std::ostream& os, const PointNd<T, dim>& pt)
            {
                if(pt.coords_.size() > 0)
                {
                    os << "(" << pt.coords_[0];
                    for(int i = 1; i < pt.coords_.size(); i++)
                    {
                        os << ", " << pt.coords_[i];
                    }
                    os << ")" << std::endl;
                }
                else
                {
                    os << "Empty" << std::endl;
                }

                return os;
            }
    };
}

int main()
{
    First::Point3d point1(1, 2, 3);
    std::cout << point1;
    
    Second::Point3d point2(3, 4, 5);
    std::cout << point2;

    Third::PointNd<int, 3> point3({5, 6, 7, 8, 9});
    std::cout << point3;
    std::cout << point3[0] << std::endl;

    system("pause");
    return 0;
}