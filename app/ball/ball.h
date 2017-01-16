#ifndef BALL_H
#define BALL_H

#include <cmath>

struct Rect {
    int x;
    int y;
    int w;
    int h;
};

struct Ball {
public:
    float x;
    float y;
    float x1;
    float y1;
    Rect  bounds;
    float gravity  = 0.9;
    float friction = 0.99;
    float bounce   = 0.85;

    void run()
    {
        float vx = x - x1;
        float vy = y - y1;

        applyFriction( vx, vy );

        x1 = x;
        y1 = y;

        x += vx;
        y += vy;

        applyGravity( y );
        applyBoundary( vx, vy );
    }

    void applyGravity( float &y )
    {
        y += gravity;
    }

    void applyFriction( float &vx, float &vy )
    {
        vx *= friction;
        vy *= friction;
    }

    void applyBoundary( float vx, float vy )
    {
        if ( x < bounds.x )
        {
            x  = bounds.x;
            x1 = x + vx * bounce;
        }
        if ( x > bounds.x + bounds.w )
        {
            x  = bounds.x + bounds.w;
            x1 = x + vx * bounce;
        }
        if ( y < bounds.y )
        {
            y  = bounds.y;
            y1 = y + vy * bounce;
        }
        if ( y > bounds.y + bounds.h )
        {
            y  = bounds.y + bounds.h;
            y1 = y + vy * bounce;
        }
    }

    void applyForce( float x, float y )
    {
        x1 += x;
        y1 += y;
    }

    void moveTo( float x, float y )
    {
        this->x  = x;
        this->y  = y;
        this->x1 = x;
        this->y1 = y;
    }

    void setForce( float x, float y )
    {
        x1 = this->x + x;
        y1 = this->y + y;
    }

    void gravitateTo( float x, float y, float mass )
    {
        float angle = atan2( y - this->y, x - this->x );
        float dx    = x - this->x;
        float dy    = y - this->y;
        float dist  = sqrt( dx * dx + dy * dy );
        float vx    = cos( angle ) * mass / ( dist * dist );
        float vy    = sin( angle ) * mass / ( dist * dist );

        this->x1 -= vx;
        this->y1 -= vy;
    }

};

#endif //BALL_H
