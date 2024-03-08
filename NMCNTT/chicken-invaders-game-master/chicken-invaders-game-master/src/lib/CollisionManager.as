package lib
{
	import flash.geom.Point;
	
	import models.PlayingGame;
	import views.Assets;
	import objects.Bullet;
	import objects.Chicken;
	import views.Game;
	/**
	 *  Detecting the collision between the spaceship, bullets and the chickens
	 * 
	 * @author Peter Shodeinde
	 * */

	public class CollisionManager
	{
		private var play:PlayingGame;
		private var p1:Point = new Point();
		private var p2:Point = new Point();
		public function CollisionManager(play:PlayingGame)
		{
			this.play = play;
		}
		
		public function update():void
		{
			fighterAndChickens();
			bulletsAndChickens();
			
		}
		// Collision between the spaceship fighter and the chicken
		public function fighterAndChickens():void
		{
			var cc:Array = play.chickenManager.chickens;
			var c:Chicken;
			
			var len:int = cc.length;
			for(var i:int=len-1; i>=0; i--)
			{
				c = cc[i];
				p1.x = play.fighter.x;
				p1.y = play.fighter.y;
				p2.x = c.x;
				p2.y = c.y;
				// Check the collision of the fighter and the chicken 
				// GAME OVER if true 
				if(Point.distance(p1, p2) < c.pivotY + play.fighter.pivotY)
				{
					
					play.game.changeState(Game.GAME_OVER_MODEL);
					
				}
			}
			
		}
		
		// Collision between the spaceship fighter and the chicken
		public function bulletsAndChickens():void
		{
			var fc:Array = play.bulletManager.bullets;
			var cc:Array = play.chickenManager.chickens;
			
			var b:Bullet;
			var c:Chicken;
			
			var len:int = fc.length;
			var len2:int = cc.length;
			
			for(var i:int=len-1; i>=0; i--)
			{
				b = fc[i];  //  get a reference to the current bullet
				for(var j:int=len2-1; j>=0; j--)
				{
					c = cc[j];
					
					// get the position of the bullet
					p1.x = b.x;
					p1.y = b.y;
					p2.x = c.x;
					p2.y = c.y;
					
					// checking if there is any collision between the bullet and the chicken
					if(Point.distance(p1, p2) < c.pivotY + b.pivotY)
					{
						Assets.explosion.play();
						play.explosionManager.spawn(c.x, c.y);
						play.bulletManager.destroyBulletFired(b);
						play.chickenManager.destroyChicken(c);
						play.score.addScore(Math.floor(Math.random() * 200));
						
					}
				}
				
				
			}
		}
	}
}