<?php

/**
 * @file
 *   Github post receive data unserializer plugin.
 */

$plugin = array(
  'title' => t('URL encoded key=value'),
  'handler' => array(
    'class' => 'Webhook_Plugins_Unserializer_UrlEncoded',
  ),
);

/**
 * Webhook unserializer plugin for Github post receive data.
 */
class Webhook_Plugins_Unserializer_UrlEncoded implements Webhook_Plugins_Unserializer_Interface {
  public function unserialize($data) {
    $vars = array();
    parse_str($data, $vars);
    return $vars;
  }
}
