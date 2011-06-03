<?php

class layout2 extends layout {

        /**
     * method for parsing a module menu.
     * A module menu is a menu connected to a main menu item.
     *
     * @param   array   menu to parse
     * @return  string  containing menu in html form ul li
     */
    public static function parseModuleMenu($menu, $type){
        $str = '';
        echo "hello world";
        $str.= MENU_LIST_START . "\n";
        $num_items = $ex = count($menu);

        foreach($menu as $k => $v){
            if ( !empty($v['auth'])){
                if (!session::isUser()) continue;
                if (!session::isAdmin() && $v['auth'] == 'admin') continue;
                if (!session::isSuper()  && $v['auth'] == 'super') continue;
            }

            $str .= MENU_SUBLIST_START;
            if ($num_items && ($num_items != $ex) ){
                $str .= MENU_SUB_SEPARATOR;
            }
            $num_items--;

            

            $str .= create_link($v['url'], $v['title']);
            $str .= MENU_SUBLIST_END;
        }
        $str.= MENU_LIST_END . "\n";
        return $str;
    }
    /**
     * function for parsing MAIN menu list.
     * Main menu is the menu holding all info about modules in database.
     * Therefore it is also some sort of top level module menu.
     */
    public static function parseMainMenuList (){

        $module_base = uri::$info['module_base'];

        $menu = array();
        $menu = self::$menu['main'];
        $str = $css = '';
        foreach($menu as $k => $v){
            if ( !empty($v['auth'])){
                if (!session::isUser()) continue;
                if (!session::isAdmin() && $v['auth'] == 'admin') continue;
                if (!session::isSuper()  && $v['auth'] == 'super') continue;
            }

            
            $str.="<li>";
            $link = create_link( $v['url'], $v['title']);
            $str.=  $link;
            if (isset($v['sub'])){
                $str .= self::parseMainMenuList($v['sub']);
            }
            $str .= "</li>\n";
        }
        return $str;

    }

    /**
     * method for getting main module menu as html
     *
     * @return string containing menu module menu as html
     */
    public static function getMainMenu(){

        $str = '';
        $str.= '<ul>' . "\n";
        $str.= self::parseMainMenuList();
        $str .= "</ul>\n";
        return $str;
    }
}


class mainTemplate extends template {

/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ ?>
<!doctype html>
<html lang="<?=register::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<title><?php echo $_SERVER['HTTP_HOST']?> :: <?php echo template::getTitle(); ?></title>
    <link rel="stylesheet" type="text/css" href="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/themes/ui-lightness/jquery-ui.css" />


    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.5.0/jquery.min.js"></script>
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/jquery-ui.js"></script>


<?php

echo template::getMeta();
template::setCss('/templates/mandlen/common.css?version=16');


$options = array('load_ini_file' => true, 'no_cache' => true);

//template::setCss('/templates/vertical-accordian/css/my.css');
//template::setCss('/templates/vertical-accordian/css/skins/graphite.css');
//template::setCss('/templates/vertical-accordian/css/skins/my-blue.css');

//template::setJs('/templates/vertical-accordian/js/jquery.cookie.js');
//template::setJs('/templates/vertical-accordian/js/jquery.hoverIntent.minified.js');
//template::setJs('/templates/vertical-accordian/js/jquery.dcjqaccordion.2.2.js');
//template::setJs('/templates/vertical-accordian/default.js');


echo template::getCss();
echo template::getInlineCss();

echo template::getJs();
echo template::getInlineJs();
?>

</head>

<div id ="hidden">
<a href="/account/login/index">logon</a>
</div>
<div id="page">

    <div id="header">
        <?php if (empty(register::$vars['coscms_main']['logo'])) { ?>
            <div id ="logo_title"><a href="/"><?php echo $_SERVER['HTTP_HOST']?></a></div><?php
        } else { ?>
            <div id = "logo_img"><a href="/"><img alt="<?php echo $_SERVER['HTTP_HOST']?>" src="/logo/<?=register::$vars['coscms_main']['logo']?>" /></a></div><?php
        } ?>
        <div id="main_menu"><?php
echo layout2::getMainMenu();

?>

    </div>
        <div id ="top_blocks">
<?php

$blocks = layout2::getTopBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
        </div>
    </div>
    
    <div id="sidebar_left">
        <div id ="block_menu">
<?php

$blocks = layout2::getBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
    </div></div>
    <div id="sidebar_right">
        <div id ="block_menu_right">
<?php

$blocks_sec = layout2::getBlocksSec();
foreach ($blocks_sec as $key => $val){
      print $val;
}


?>
        </div>
   </div>
    <div id="content">
        <div id="module_menu">
<?php

echo layout2::getModuleMenu();

?>
        </div>
        <div id="system_message"><p>
<?php

echo session::getActionMessage();

?>
        </p></div>

<?php

// content of loaded module will be printed

}

/**
 * method for print footer of page
 */
public static function printFooter(){

?>

            <div id="end_content">
<?php

echo template::getEndContent();

?>
        </div>
    </div>
    <div id="footer">
    <?=register::$vars['coscms_main']['footer_message']?>
    </div>
</div>
<?php

echo template::getEndHTML();

?>
</body>
</html>
<?php

}
    
// end of class 
}
