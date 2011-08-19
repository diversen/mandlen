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
