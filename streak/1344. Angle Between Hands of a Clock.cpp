class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        // aik hour me min wali sui 360 deg ghoom leti ha
        // 360/60 = 6
        // hour wali sui 12 hours me 360 deg ghoom leti ha
        // 360/12 = 30
        // but ye hour wali mins k sath b move karti ha
        // 1 hour = 60 mins so then aik hour me 30deg then 30/60 = 0.5
        // formula = hour * 30 + min * 0.5 abs diff with min * 6
        double hoursAngle = (hour % 12) * 30 + minutes * 0.5;
        double minutesAngle = minutes * 6;
        double diff = abs(hoursAngle - minutesAngle);
        return min(diff, 360 - diff);
    }
};