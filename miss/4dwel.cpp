#include <bits/stdc++.h>
using namespace std;
#define ld long double

const ld EPSILON = 1e-16;

struct Point4D {
  ld x, y, z, w;

  Point4D operator+(const Point4D &other) const {
    return {x + other.x, y + other.y, z + other.z, w + other.w};
  }

  Point4D operator-(const Point4D &other) const {
    return {x - other.x, y - other.y, z - other.z, w - other.w};
  }

  Point4D operator*(ld scalar) const {
    return {x * scalar, y * scalar, z * scalar, w * scalar};
  }
  Point4D operator/(ld scalar) const {
    return {x / scalar, y / scalar, z / scalar, w / scalar};
  }

  ld dot(const Point4D &other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
  }

  ld norm() const { return sqrt(x * x + y * y + z * z + w * w); }
};

struct Sphere4D {
  Point4D center;
  ld radius;

  Sphere4D(const Point4D &c, ld r) : center(c), radius(r) {}

  bool contains(const Point4D &p) const {
    return (p - center).norm() <= radius + EPSILON;
  }
};

Point4D computeCenter2Points(const Point4D &p1, const Point4D &p2) {
  return (p1 + p2) / 2.0;
}

Point4D computeCenter3Points(const Point4D &p1, const Point4D &p2,
                             const Point4D &p3) {
  Point4D a = p2 - p1;
  Point4D b = p3 - p1;
  ld d1 = a.dot(a), d2 = b.dot(b), d3 = a.dot(b);
  ld denom = 2 * (a.dot(a) * b.dot(b) - d3 * d3);
  assert(fabs(denom) > EPSILON);

  ld u = (d1 * b.dot(b) - d3 * d2) / denom;
  ld v = (d2 * a.dot(a) - d3 * d1) / denom;
  Point4D center = p1 + a * u + b * v;
  return center;
}

Point4D computeCenter4Points(const Point4D &p1, const Point4D &p2,
                             const Point4D &p3, const Point4D &p4) {
  Point4D a = p2 - p1, b = p3 - p1, c = p4 - p1;
  ld d1 = a.dot(a), d2 = b.dot(b), d3 = c.dot(c), d4 = a.dot(b), d5 = a.dot(c),
     d6 = b.dot(c);
  ld denom = 2 * (a.dot(a) * (b.dot(b) * c.dot(c) - d6 * d6) -
                  d4 * (d4 * c.dot(c) - d5 * d6) +
                  d5 * (d4 * d6 - b.dot(b) * a.dot(c)));
  ld u =
      (d1 * (b.dot(b) * c.dot(c) - d6 * d6) - d4 * (d1 * c.dot(c) - d5 * d6) +
       d5 * (d4 * d6 - b.dot(b) * a.dot(c))) /
      denom;
  ld v =
      (d2 * (a.dot(a) * c.dot(c) - d5 * d5) -
       d4 * (a.dot(a) * d6 - d5 * a.dot(c)) + d5 * (d4 * d5 - d1 * c.dot(c))) /
      denom;
  ld w =
      (d3 * (a.dot(a) * b.dot(b) - d4 * d4) -
       d5 * (a.dot(a) * d6 - d4 * a.dot(c)) + d4 * (d1 * b.dot(b) - d4 * d5)) /
      denom;
  Point4D center = p1 + a * u + b * v + c * w;
  return center;
}
Point4D computeCenter5Points(const Point4D &p1, const Point4D &p2,
                             const Point4D &p3, const Point4D &p4,
                             const Point4D &p5) {
  // Matrix to solve Ax = B
  vector<vector<ld>> A(4, vector<ld>(4));
  vector<ld> B(4);
  // Fill matrix A and vector B based on the hypersphere equation
  auto fillRow = [&](int row, const Point4D &a, const Point4D &b) {
    Point4D diff = b - a;
    A[row][0] = diff.x;
    A[row][1] = diff.y;
    A[row][2] = diff.z;
    A[row][3] = diff.w;
    B[row] = 0.5 * (diff.dot(diff) - (b.dot(b) - a.dot(a)));
  };
  fillRow(0, p1, p2);
  fillRow(1, p1, p3);
  fillRow(2, p1, p4);
  fillRow(3, p1, p5);
  // Solve the linear system Ax = B using Gaussian elimination
  for (int i = 0; i < 4; ++i) {
    // Find the pivot
    int pivot = i;
    for (int j = i + 1; j < 4; ++j) {
      if (fabs(A[j][i]) > fabs(A[pivot][i])) {
        pivot = j;
      }
    }
    // Swap rows
    swap(A[i], A[pivot]);
    swap(B[i], B[pivot]);
    // Ensure the pivot is non-zero
    assert(fabs(A[i][i]) > EPSILON);
    // Normalize the pivot row
    ld pivotValue = A[i][i];
    for (int j = i; j < 4; ++j) {
      A[i][j] /= pivotValue;
    }
    B[i] /= pivotValue;
    // Eliminate the current column from the other rows
    for (int j = 0; j < 4; ++j) {
      if (j == i)
        continue;
      ld factor = A[j][i];
      for (int k = i; k < 4; ++k) {
        A[j][k] -= factor * A[i][k];
      }
      B[j] -= factor * B[i];
    }
  }
  // The result is now in B
  return {B[0], B[1], B[2], B[3]};
}
Sphere4D makeSphereFromBoundary(const std::vector<Point4D> &boundary) {
  int n = boundary.size();
  Point4D center;
  ld radius = 0;
  if (n == 1) {
    center = boundary[0];
    radius = 0;
  } else if (n == 2) {
    center = computeCenter2Points(boundary[0], boundary[1]);
    radius = (boundary[0] - center).norm();
  } else if (n == 3) {
    center = computeCenter3Points(boundary[0], boundary[1], boundary[2]);
    radius = (boundary[0] - center).norm();
  } else if (n == 4) {
    center = computeCenter4Points(boundary[0], boundary[1], boundary[2],
                                  boundary[3]);
    radius = (boundary[0] - center).norm();
  } else if (n == 5) {
    center = computeCenter5Points(boundary[0], boundary[1], boundary[2],
                                  boundary[3], boundary[4]);
    radius = (boundary[0] - center).norm();
  }
  return Sphere4D(center, radius);
}

Sphere4D welzlRecursive(std::vector<Point4D> &points,
                        std::vector<Point4D> boundary, int n) {
  if (n == 0 || boundary.size() == 4) {
    return makeSphereFromBoundary(boundary);
  }
  Point4D p = points[n - 1];
  Sphere4D sphere = welzlRecursive(points, boundary, n - 1);
  if (sphere.contains(p)) {
    return sphere;
  }
  boundary.push_back(p);
  return welzlRecursive(points, boundary, n - 1);
}
Sphere4D welzl(std::vector<Point4D> &points) {
  random_device rd;
  mt19937 g(rd());
  shuffle(points.begin(), points.end(), g);
  return welzlRecursive(points, {}, points.size());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;

  cin >> n;

  vector<Point4D> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y >> points[i].z >> points[i].w;
  }

  Sphere4D enclosingSphere = welzl(points);
  cout << fixed << setprecision(10);
  cout << enclosingSphere.center.x << " " << enclosingSphere.center.y << " "
       << enclosingSphere.center.z << " " << enclosingSphere.center.w << "\n";

  return 0;
}
