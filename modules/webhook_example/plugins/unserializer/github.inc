<?php

/**
 * @file
 *   Github post receive data unserializer plugin.
 */

$plugin = array(
  'title' => t('Github'),
  'handler' => array(
    'class' => 'Webhook_Example_Plugins_Unserializer_Github',
  ),
);

/**
 * Webhook unserializer plugin for Github post receive data.
 */
class Webhook_Example_Plugins_Unserializer_Github implements Webhook_Plugins_Unserializer_Interface {
  public function unserialize($data) {
    $url = webhook_load_unserializer('urlencoded');
    $vars = $url->unserialize($data);

    $json = webhook_load_unserializer('json');
    return $json->unserialize($vars['payload']);
  }
}
