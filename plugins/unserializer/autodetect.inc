<?php

/**
 * @file
 *   Auto detect unserializer plugin.
 */

$plugin = array(
  'title' => t('Autodetect'),
  'handler' => array(
    'class' => 'Webhook_Plugins_Unserializer_Autodetect',
  ),
);

/**
 * Webhook unserializer plugin for JSON.
 */
class Webhook_Plugins_Unserializer_Autodetect implements Webhook_Plugins_Unserializer_Interface {
  public function unserialize($data) {
    switch($_SERVER['CONTENT_TYPE']) {
      case 'application/json':
      case 'application/javascript': //JSON-P
        $handler = 'json';
        break;
      case 'text/xml':
      case 'application/xml':
        $handler = 'xml';
        break;
      case 'x-www-form-urlencoded':
        $handler = 'urlencoded';
        break;
      default:
        throw new Webhook_Plugins_Unserializer_InvalidDataException('Invalid content type.');
    }

    $plugin = webhook_load_unserializer($handler);
    return $plugin->unserialize($data);
  }
}
