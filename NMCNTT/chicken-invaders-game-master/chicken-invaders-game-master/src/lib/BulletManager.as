package lib
{
	import com.leebrimelow.starling.StarlingPool;
	
	import models.PlayingGame;
	import views.Assets;
	import objects.Bullet;
	/**
	 * Creating the interaction of the bullet in the game. Then firing, disappearing of the bullet etc
	 * @author Peter Shodeinde
	 * 
	 **/
	public class BulletManager
	{
		private var play:PlayingGame;
		public var bullets:Array;
		private var bulletPool:StarlingPool;
		public var count:int = 0;
		
		public function BulletManager(play:PlayingGame)
		{
			this.play = play;
			bullets = new Array();
			bulletPool = new StarlingPool(Bullet, 100);
		}
		
		
		
		// An update function for the bullet when fired, the bullet disappear when it reaches the top of the game
		public function update():void
		{
			var b:Bullet;
			var len:int = bullets.length;
			for (var i:int=len-1; i >= 0; i--)
			{
				b = bullets[i];
				b.y -= 25;
				if(b.y < 0)
					destroyBulletFired(b);
			}
			
			if(play.fire && count %10 == 0)
				fire();
			
			count++;
		}
		
		
		// for firing the bullet over again from the memory in the bulletPool
		
		private function fire():void
		{
			var b:Bullet = bulletPool.getSprite() as Bullet;
			play.addChild(b);
			b.x = play.fighter.x - 10;
			b.y = play.fighter.y - 15;
			bullets.push(b);
			
			b = bulletPool.getSprite() as Bullet;
			play.addChild(b);
			b.x = play.fighter.x + 10;
			b.y = play.fighter.y - 15;
			bullets.push(b);
			Assets.shoot.play();
			
		}
		
		public function destroyBulletFired(b:Bullet):void
		{
			var len:int = bullets.length;
			for (var i:int=0; i < len; i++)
			{
				if(bullets[i] == b)
				{
					bullets.splice(i, 1);
					b.removeFromParent(true);
					bulletPool.returnSprite(b);
				
				}
			}
			
		}
		
		// removing the bullet pool to destroy the bullet objects
		public function destroy():void
		{
			bulletPool.destroy();
			bulletPool = null;
			bullets = null;
		}
		
		
	}
}