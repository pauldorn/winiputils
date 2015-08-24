{
  'targets': [
    {
      'target_name': 'winiputils',
      'sources': [
        'src/binding.cc',
      ],
      'include_dirs': [
        "<!(node -e \"require('nan')\")",
      ],
      'conditions': [
        [ 'OS=="win"', {
          'include_dirs': [
            'deps/winpcap/Include',
          ],
          'defines': [
            'WPCAP',
          ],
          'conditions': [
            [ 'target_arch=="ia32"', {
              'link_settings': {
                'libraries': ['ws2_32.lib'],
              },
            }, {
              'link_settings': {
                'libraries': ['Iphlpapi.lib', 'ws2_32.lib'],
              },
            }],
          ],
        }, {
          # POSIX
          'link_settings': {
            'libraries': [],
          },
        }],
      ],
    },
  ],
}