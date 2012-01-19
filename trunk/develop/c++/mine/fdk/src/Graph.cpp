#include <fdk/Graph.h>


namespace fdk
{
	namespace graph
	{
		Point::Point()
			: x(0)
			, y(0)
		{
		}

		Point::Point(int x, int y)
		{
			reset(x, y);
		}

		void Point::reset(int _x, int _y)
		{
			x = _x;
			y = _y;
		}

		void Point::offset(int cx, int cy)
		{
			x += cx;
			y += cy;
		}

		bool Point::operator==(const Point& o) const
		{
			return x == o.x && y == o.y;
		}

		Size::Size()
			: cx(1)
			, cy(1)
		{
		}

		Size::Size(int cx, int cy)
		{
			reset(cx, cy);
		}

		void Size::reset(int _cx, int _cy)
		{
			cx = _cx;
			cy = _cy;
		}

		bool Size::operator==(const Size& o) const
		{
			return cx == o.cx && cy == o.cy;
		}

		Rect::Rect()
			: orignPoint()
			, size()
		{
		}

		Rect::Rect(const Point& orignPoint, const Size& size)
		{
			reset(orignPoint, size);
		}

		void Rect::reset(const Point& _orignPoint, const Size& _size)
		{
			orignPoint = _orignPoint;
			size = _size;
		}

		Point Rect::oppositePoint() const
		{
			return Point(orignPoint.x+size.cx, orignPoint.y+size.cy);
		}
		
		Point Rect::centerPoint() const
		{
			return Point(orignPoint.x+size.cx/2, orignPoint.y+size.cy/2);
		}

		Point Rect::minPoint() const
		{
			return Point(minValue(orignPoint.x, oppositePoint().x), minValue(orignPoint.y, oppositePoint().y));
		}

		Point Rect::maxPoint() const
		{
			return Point(maxValue(orignPoint.x, oppositePoint().x), maxValue(orignPoint.y, oppositePoint().y));
		}
		
		bool Rect::isPointIn(const Point& point) const
		{
			const Point _minPoint = minPoint();
			const Point _maxPoint = maxPoint();
			return _minPoint.x <= point.x && point.x < _maxPoint.x
				&& _minPoint.y <= point.y && point.y < _maxPoint.y;
		}
		
		bool Rect::intersect(Rect& output, const Rect& o) const
		{
			const Point _minPoint = minPoint();
			const Point _maxPoint = maxPoint();
			const Point o_minPoint = o.minPoint();
			const Point o_maxPoint = o.maxPoint();
			if (o_maxPoint.x <= _minPoint.x || _maxPoint.x <= o_minPoint.x || 
				o_maxPoint.y <= _minPoint.y || _maxPoint.y <= o_minPoint.y)
			{
				return false;
			}
			output.orignPoint.reset(maxValue(_minPoint.x, o_minPoint.x), maxValue(_minPoint.y, o_minPoint.y));
			const Point outOppositePoint(minValue(_maxPoint.x, o_maxPoint.x), minValue(_maxPoint.y, o_maxPoint.y));
			output.size.reset(outOppositePoint.x-orignPoint.x, outOppositePoint.y-orignPoint.y);
			return true;
		}
	}
}
