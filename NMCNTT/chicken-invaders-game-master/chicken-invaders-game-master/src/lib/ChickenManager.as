package lib
{
	import com.leebrimelow.starling.StarlingPool;
	
	import models.PlayingGame;
	
	import objects.Bullet;
	import objects.Chicken;
	import starling.core.Starling;
	
	/**
	 * Creating the interaction of the bullet in the game. Then firing, disappearing of the bullet etc
	 * @author Peter Shodeinde  
	 **/	
	public class ChickenManager
	{
		private var play:PlayingGame;
		public var chickens:Array;
		private var chickenPool:StarlingPool;
		public var count:int = 0;
		
		public function ChickenManager(play:PlayingGame)
		{
			this.play = play;
			chickens = new Array();
			chickenPool = new StarlingPool(Chicken, 30);
		}
		
		
		
		
		public function update():void
		{
			if (Math.random() < 0.05)
				spawn();
			
			var c:Chicken;
			var len:int = chickens.length;
			
			for (var i:int=len-1; i >= 0; i--)
			{
				c = chickens[i];
				c.y += 8;
				if(c.y > 800)
					destroyChicken(c)
			}
			
			
		}
		
		
		/*
		 * 
		*/
		
		private function spawn():void
		{
			var c:Chicken = chickenPool.getSprite() as Chicken;
			Starling.juggler.add(c);
			chickens.push(c);
			c.x = Math.random() * 600 + 100;
			c.y = -50;
			play.addChild(c);
			
			
		}
		
		public function destroyChicken(c:Chicken):void
		{
			var len:int = chickens.length;
			for (var i:int=0; i < len; i++)
			{
				if (c == chickens[i])
				{
					chickens.splice(i, 1);
					Starling.juggler.remove(c);
					c.removeFromParent(true);
					chickenPool.returnSprite(c);
				}
			}
			
		}
		public function destroy():void
		{
			chickenPool.destroy();
			chickenPool = null;
			chickens = null;
		}
		
		
	}
}