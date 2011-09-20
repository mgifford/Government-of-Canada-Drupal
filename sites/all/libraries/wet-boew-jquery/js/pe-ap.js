/*!
 * jQuery integration v1.2 / Intégration jQuery v1.2
 * Web Experience Toolkit (WET) / Boîte à outils de l'expérience Web (BOEW)
 * Terms and conditions of use: http://tbs-sct.ircan.gc.ca/projects/gcwwwtemplates/wiki/Terms
 * Conditions régissant l'utilisation : http://tbs-sct.ircan.gc.ca/projects/gcwwwtemplates/wiki/Conditions
 */

/** JavaScript / JQuery Capabilities with Name-spaced HTML **/

    
var PE = {  
    progress: function(props){
	
	   /** Page Language - is set by the Meta Data Element [ dc.language ] **/
	    PE.language = jQuery("meta[name='dc.language'], meta[name='dcterms.language']").attr('content'); 
	   /** Page Language - end **/
	   /** JS Location - The browser helps set this up for us **/
           
            PE.liblocation = '/sites/all/libraries/wet-boew-jquery/js/'; 
	    //PE.liblocation = jQuery("script[id='progressive']").attr('src').replace("pe-ap.js","");
            
	    /** JS Location - end **/
	    PE.uiloaded = false;
	    /** jquery ui load state **/

	    /** Load mandatory supporting library and plugins features **/
	    PE.load('wet-boew.utils.js');
	    PE.load('wet-boew.skipnav.js');
	    PE.load('jquery.hotkeys.js');
	    PE.load('wet-boew.tooltips.js');
	    
	    /** Load supporting plugins **/
	    
	    PE.load('wet-boew.pngfix.js');
	    PE.load('wet-boew.equalheight.js');
	    PE.load('wet-boew.storage.js');
	    
		PE.parameters = props /** DEPRECATED: Backward Compatibility **/ ;
		
		for(key in PE.parameters) {
			/** This is new functionality that will allow for plug-ins to be dynamically loaded per page
			 *  Approach : Parameters passed to be PE object are in a Key / Value pair
			 *  Data Model : Key - is the name of the property which will be the name of the plug-in file
			 *  		   : Value - will be the parameters ( if any ) to pass to the plug-in main function 
			 *  Notes : All methods will be fired on the Document.Ready JQuery to ensure proper DOM Loading
			 *  **/
			 var myPluginLoader = PE.liblocation+"plugins/wet-boew."+[key]+".js?";
			 
			 if ( typeof(PE.parameters[key]) == 'object' )
			 {
				 var nCount = 0;
				 for (var name in PE.parameters[key])
				 {
					 var aMpersand = (nCount > 0 ) ? "&" : "" ;
					 myPluginLoader += "" + aMpersand + name + "=" +  escape(PE.parameters[key][name]);
					 ++nCount;
				 }
			 }else {
				 myPluginLoader += "id=" +  PE.parameters[key];
			};
			/** Append the script to the page DOM for autoloading ( Safari 2 & Opera 8 safe ) **/
			document.write('<script type="text/javascript" src="'+myPluginLoader+'" id="wet-boew_plugin_'+[key]+'"><\/script>');
			
		
		}			
    },
    
	   /** Load Required Obligatory Scripts
	    *   Method: Brute force to ensure Safari 2 compatiblity
	    *   TODO: We may want to look at creator a more elegant Loader method
	    *   	  maybe through an ini file
	    *  **/
	    
   load: function(jsSrc, jParam){
    	if (jParam){
    		document.write('<script type="text/javascript" src="'+PE.liblocation+"lib/"+jsSrc+'?'+jParam+'"><\/script>');
    	}else {
    		document.write('<script type="text/javascript" src="'+PE.liblocation+"lib/"+jsSrc+'"><\/script>');
    	}
    	
    },

     load_ui: function(themeenabled){
        // stop the ui from being loaded more than once
	if (PE.uiloaded){ return true };

	var use_theme = (typeof(themeenabled)!='undefined') ? themeenabled : "use-theme";
	/** load the jquery ui file **/
	document.write('<script type="text/javascript" src="'+PE.liblocation +"lib/ui/jquery-ui.min.js"+'"><\/script>');

	if (use_theme != "no-theme") {
	// load the default style
 	var $link = jQuery('<link rel="stylesheet" type="text/css" media="all" />').appendTo('head');
        
	$link.attr(
        {
            	href: PE.liblocation + "support/ui/themes/default/jquery-ui.css",
            	rel: 'stylesheet',
            	type: 'text/css',
            	media: 'all'
        	});
	}
	PE.uiloaded = true;
    },
    
    /** Requested by User 
     *  - Suggestion :  http://tbs-sct.ircan.gc.ca/issues/796?lang=eng
     ***********************/
    loadExternal: function(jsSrc){
      
    },
    
    loadParams : function (name, plugin){
    	return jQuery("script[id='wet-boew_plugin_" + name + "']").attr('src');
    }
};


//Functionality to detect if CSS enabled at the browser level
jQuery.extend(window, {cssEnabled : null});
jQuery(document).ready(function() {
    cssTest = jQuery("<div id=\"cssTest\" style=\"height:0px;\">&#160;</div>");
    jQuery("body").append(cssTest);
    cssEnabled = cssTest.height() === 0;
    jQuery.extend(window, {cssEnabled : cssEnabled});
	jQuery("#cssTest").remove();
});


