class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        // jo point sab se qareeb ha us ko check karo k agar wo overlap ho raha then true else false
        int xi, yi;
        if (x1 > xCenter)
        {
            xi = x1;
        }
        else if (x2 < xCenter)
        {
            xi = x2;
        }
        else
        {
            xi = xCenter;
        }
        if (y1 > yCenter)
        {
            yi = y1;
        }
        else if (y2 < yCenter)
        {
            yi = y2;
        }
        else
        {
            yi = yCenter;
        }

        // now distance cehck karo circle se
        int d = sqrt((xi - xCenter) * (xi - xCenter) + (yi - yCenter) * (yi - yCenter));
        return d <= radius;
    }
};