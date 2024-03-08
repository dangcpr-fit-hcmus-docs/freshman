package objects
{
	import starling.extensions.PDParticleSystem;
	import starling.textures.Texture;
	
	import views.Assets;
	/**
	 *   Creating the explosion objects
	 * 	@author Peter Shodeinde
	 * 
	 * */
	public class Explosion extends PDParticleSystem
	{
		public function Explosion()
		{
			super(XML(new Assets.explosionXML()), Assets.ta.getTexture("explosion"));
		}
	}
}