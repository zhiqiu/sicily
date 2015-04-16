class Robot {
public:
         Robot();                 /* default constructor, initialize at (0,0) */
         Robot(Position pos);     /* initialize at pos */
         void Move(char Dir);     /* Dir could be 'N', 'E', 'S', 'W', for other characters, the robot don’t move */
         Position GetPosition();  /* return current position */
private:
         Position currentPos;
};

Robot :: Robot()
{
    currentPos.x = 0;
    currentPos.y = 0;
}

Robot :: Robot(Position pos)
{
    currentPos.x = pos.x;
    currentPos.y = pos.y;
}

void Robot :: Move(char Dir)
{
    switch(Dir)
    {
        case 'N':
          currentPos.y += 1;
          break;
        case 'E':
          currentPos.x += 1;
          break;
        case 'S':
          currentPos.y -= 1;
          break;
        case 'W':
          currentPos.x -= 1;
          break;
        default:
          break;
    }
}

Position Robot :: GetPosition()
{
    return currentPos;
}                                 
