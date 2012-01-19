#ifndef __FDK_GRAPH_H_INCLUDE__
#define __FDK_GRAPH_H_INCLUDE__
#include "Base.h"

namespace fdk
{
	namespace graph
	{
		#include "_AutoOperator.h"
		
		class FDK_API Point
		{
		public:
			Point();
			Point(int x, int y);
			void reset(int x, int y);
			void offset(int cx, int cy);
			bool operator==(const Point& o) const;
			int x;
			int y;
		};

		class FDK_API Size
		{
		public:
			Size();
			Size(int cx, int cy);
			void reset(int cx, int cy);
			bool operator==(const Size& o) const;
			int cx;
			int cy;
		};

		class FDK_API Rect
		{
		public:
			Rect();
			Rect(const Point& orignPoint, const Size& size);
			void reset(const Point& orignPoint, const Size& size);
			Point oppositePoint() const; // ¶Ô½Ç(²»°üÀ¨)
			Point centerPoint() const;
			Point minPoint() const;
			Point maxPoint() const;
			bool isPointIn(const Point& point) const;
			bool intersect(Rect& output, const Rect& o) const;
			bool operator==(const Rect& o) const;
			Point orignPoint;
			Size size;
		};
	}
}

#endif
